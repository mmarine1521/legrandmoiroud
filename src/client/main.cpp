#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.h"

using namespace std;
using namespace state;

int main(int argc,char* argv[]) 
{
    //Exemple exemple;
    //exemple.setX(53);

    cout << "It works !" << endl;

    Pays EuropeNord(1,EUROPE) ;
    int a = EuropeNord.getIdPays() ;
    cout << "ID de l'Europe du Nord"<< a << endl ;

    return 0;
}
