#ifndef HEARLER_H
#define HEARLER_H

#include <Personnage.h>


class Healer : public Personnage
{
    public:
        Healer();
        virtual ~Healer();
        Healer (const Healer& other);
        int getStrength() const{return this->strength;}
        int getPower() const{return this->power;}
        int getMagicalArmor() const{return this->magicalArmor;}
        int getPhysicalArmor() const{return this->physicalArmor;}
        int getLifePoint() const{return this->lifePoint;}
        void setStrength(int){this->strength=0;}
        void setPower(int i){this->power=i;}
        void setMagicalArmor(int i){this->magicalArmor=i;}
        void setPhysicalArmor(int){this->physicalArmor=0;}
        void setLifePoint(int i){this->lifePoint=i;}

        static Personnage* __stdcall Create() {return new Healer();}

    protected:

    private:
        int lifePoint;
        int power;
        int strength;
        int magicalArmor;
        int physicalArmor;
};

#endif // HEARLER_H