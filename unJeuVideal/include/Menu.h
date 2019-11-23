#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Team.h"

using namespace sf;
using namespace std;

class Menu:RenderWindow
{
    public:
        Menu();
        int choix();

        vector<Personnage> initialisation();
   // vector<Mob> initialisationEnnemy();
        bool findPersonnage(Team, Personnage);
      //  bool findMob(Team, Mob);



};

const string _BACK="_back";
const string _ICON="icon_";


#endif // MENU_H

