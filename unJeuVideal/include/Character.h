#ifndef CHARACTER_H
#define CHARACTER_H

#include "Attack.h"


#include <string>
#include "sstream"
using std::string;
using std::stringstream;

using namespace std;
class Character
{
public:
    //formes canoniques
  Character();
  Character(string);
  Character(string, int, int, int, int, int, int, Attack *);
  virtual ~Character();
  Character(const Character &other);
  Character &operator=(Character const &other)
  {
      this->lifePoint = other.lifePoint;
      this->strength = other.strength;
      this->power = other.power;
      this->magicalArmor = other.magicalArmor;
      this->physicalArmor = other.physicalArmor;
      this->speed = other.speed;
      this->lifePointMax = other.lifePointMax;

      this->name = other.name;

      this->attack[0] = other.attack[0];
      this->attack[1] = other.attack[1];
      this->attack[2] = other.attack[2];
      this->attack[3] = other.attack[3];

      this->pathFront = other.pathFront;
      this->pathBack = other.pathBack;

      return *this;
    }

    //Getters + setters
    int getStrength() const{return this->strength;}
    int getPower() const{return this->power;}
    int getMagicalArmor() const{return this->magicalArmor;}
    int getPhysicalArmor() const{return this->physicalArmor;}
    int getLifePoint() const{return this->lifePoint;}
    int getLifePointMax()const{return this->lifePointMax;}
    string getName()const{return this->name;}
    string getPath(bool);
    int getSpeed()const;

    void setStrength(int i){this->strength=i;}
    void setPower(int i){this->power=0;}
    void setMagicalArmor(int i){this->magicalArmor=0;}
    void setPhysicalArmor(int i){this->physicalArmor=i;}
    void setLifePoint(int lifePoint){this->lifePoint=lifePoint;}
    void setName(string str){this->name=str;};
    void setPath();

    //Autres

    string str(){
        stringstream stri;
        stri <<"Life Points :"<<this->lifePoint<<"\nName :"<<this->name<<"\nStrength :"<<this->strength<<"\nPower :"<<this->power<<"\nMagical Armor :"<<this->magicalArmor<<"\nPhysical Armor :"<<this->physicalArmor;
        return stri.str();
    };

    void show(void);
    bool isKO();
    Attack* getAttack();

    string sendAttack(Attack, Character*);
    static string itoa(double,int);
    static string itoa(int,int);
    static string toString(double);
	static string toString(int);


private:
    int strength;
    int power;
    int magicalArmor;
    int physicalArmor;
    int lifePoint;
    int lifePointMax;
    int speed;
    int getDamage(Attack, Character*);

    string name;

    string pathFront;
    string pathBack;

    Attack attack[4];



};

#endif // PERSONNAGE_H
