#include "Character.h"

#include"Game.h"


#include<iostream>
#include<string>


Character::Character()
{
    //ctor
    this->strength=10;
    this->power=10;
    this->lifePoint=100;
    this->magicalArmor=10;
    this->physicalArmor=10;
    this->lifePointMax=lifePoint;
    this->speed=speed;

    this->name="Brawler";

    this->attack[0] = Attack("attaque1");
    this->attack[1] = Attack("attaque2");
    this->attack[2] = Attack("attaque3");
    this->attack[3] = Attack("attaque4");
}

Character::Character(string name, int lifePoint, int strength, int power, int physicalArmor, int magicalArmor,int speed, Attack* attack)
{
    this->strength=strength;
    this->power=power;
    this->lifePoint=lifePoint;
    this->magicalArmor=magicalArmor;
    this->physicalArmor=physicalArmor;
    this->lifePointMax=lifePoint;
    this->speed=speed;

    this->name=name;

    this->attack[0] = attack[0];
    this->attack[1] = attack[1];
    this->attack[2] = attack[2];
    this->attack[3] = attack[3];


    setPath();

   // cout<<"Construction personnage "<<this->getName()<<endl;
}

Character::Character(string name)
{
    this->strength=10;
    this->power=10;
    this->lifePoint=100;
    this->magicalArmor=10;
    this->physicalArmor=10;
    this->speed=10;

    this->name=name;

    this->attack[0] = Attack("attaque1");
    this->attack[1] = Attack("attaque2");
    this->attack[2] = Attack("attaque3");
    this->attack[3] = Attack("attaque4");

     setPath();
}
Character::Character (const Character& other){
        this->lifePoint=other.lifePoint;
        this->strength=other.strength;
        this->power=other.power;
        this->magicalArmor=other.magicalArmor;
        this->physicalArmor=other.physicalArmor;
        this->speed=other.speed;
        this->lifePointMax=other.lifePointMax;


        this->name=other.name;

        this->attack[0]=other.attack[0];
        this->attack[1]=other.attack[1];
        this->attack[2]=other.attack[2];
        this->attack[3]=other.attack[3];

        this->pathFront=other.pathFront;
        this->pathBack=other.pathBack;


}

Character::~Character()
{
    //dtor

}

// pour savoir si on prends le devant ou le dos du personnage
string Character::getPath(bool front){

	if(front)
	{
	return pathFront;
	}
	else
	{
	return pathBack;
	}
}

//concatenation des différentes constantes pour savoir l'image à prendre
void Character::setPath(){

    pathBack=PATH_IMAGE+this->getName()+BACK+EXTENSION_IMAGE;
    pathFront=PATH_IMAGE+this->getName()+EXTENSION_IMAGE;

}
//pour tester si un perso est complet
void Character::show()
{
    cout << "---------------------------------------"<<endl;
    cout <<"Nom: "<<this->name<<endl;
    cout <<"PV: "<<this->getLifePoint()<<"/"<<this->getLifePointMax()<<endl;
    cout <<"Force: "<<this->getStrength()<<endl;
    cout <<"Puissance: "<<this->getPower()<<endl;
    cout <<"Reistance physique: "<<this->getPhysicalArmor()<<endl;
    cout <<"Reistance Magique: "<<this->getMagicalArmor()<<endl;
    cout << "Attaque 1: "<<endl;
	this->attack[0].toString();
	cout << "Attaque 2: "<<endl;
	this->attack[1].toString();
	cout << "Attaque 3: "<<endl;
	this->attack[2].toString();
	cout << "Attaque 4: "<<endl;
	this->attack[3].toString();
}
//on test si le personnage est tjs en vie
bool Character::isKO(){
    if(this->lifePoint<=0)
        return true;
    else
        return false;
}

//recupere l'attaque pour un personnage
Attack* Character::getAttack(){
    return this->attack;

}

int Character::getSpeed()const
{
    return speed;
}


//méthode de calcul de degats : différence entre les attributs de degats physique et magique ainsi que  l'armure armure et magique + la puissance de l'attaque
// puis on additionne ces deux valeurs
int Character::getDamage(Attack a, Character *p)
{
    double degatAD; //degat physique
    double degatAP; //degat magique
    double degat;

    if(p->strength > p->getPhysicalArmor())
    {
        degatAD=a.getPower()+(p->strength - p->getPhysicalArmor());
    }else{
        degatAD =0;
    }

    if(p->power > p->getMagicalArmor())
    {
        degatAP=a.getPower()+(p->power - p->getMagicalArmor());
    }else{
        degatAP = 0;
    }

    degat = (degatAD+degatAP);
    return (int) degat;


}


//méthode permettant à un personnage de lancer une attaque
string Character::sendAttack(Attack a, Character *p)
{
    double damage=0;
    string s;
    int pourcent;
    int proba;

    proba=(rand()%100+1);

    s=this->getName()+" lance "+a.getName()+" !\n";

    //on compare le nombre alétoire et la precision de l'attaque
    //si elle est est supérieure : on rate l'attaque et perds donc un tour
    //sinon : on inflige des degats
    if(proba >a.getPrecision()){

        s+=this->getName()+" rate son attaque !\n";
    }else{
        if(a.getPower()!=0)
        {
            damage=getDamage(a, p); //on affecte la valeur de la méthode precedente

           p->setLifePoint(p->getLifePoint()-damage);
            //inflige des degats aux personnages(le notre comme celui en face)



            //calcul le pourcentage de point de vie par rapport à la vie (restante) du personage
            pourcent=(int)(100*damage/p->getLifePointMax());

            //on vérifie que le pourcentage ne peut pas etre > 100
            if (pourcent>=100)
               pourcent=100;

            //utilisation de la méthode itoa pour convertir la valeur du pourcentage en une chaine de caractère
            s+=p->getName()+" perd "+Character::toString(pourcent)+"% de ses PV !\n";

            //si le perso n'as plus de vie, sa barre de vie affiche 0
            if (p->isKO()){
              p->setLifePoint(0);
              s+=p->getName()+" est KO!\n ";
             }


        }

    }

    return s;



}

string Character::toString(int n)
{
    return itoa(n, 10);
}

string Character::toString(double n)
{
    return itoa(n, 10);
}



//Algo permettant de convertir un entier  en une chaine de caractère
string Character::itoa(int value, int base)
{
    string buf;

        // check that the base if valid
        if (base < 2 || base > 16) return buf;

        enum { kMaxDigits = 35 };
        buf.reserve( kMaxDigits ); // Pre-allocate enough space.


        int quotient = value;

        // Translating number to string with base:
        do {
            buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
            quotient /= base;
        } while ( quotient );

        // Append the negative sign
        if ( value < 0) buf += '-';

        std::reverse( buf.begin(), buf.end() );
    return buf;
}

string Character::itoa(double value, int base) {

        string buf;

        // check that the base if valid
        if (base < 2 || base > 16) return buf;

        enum { kMaxDigits = 35 };
        buf.reserve( kMaxDigits ); // Pre-allocate enough space.


        int quotient = value;

        // Translating number to string with base:
        do {
            buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
            quotient /= base;
        } while ( quotient );

        // Append the negative sign
        if ( value < 0) buf += '-';

        std::reverse( buf.begin(), buf.end() );
        return buf;
}
