// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
/*#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}
*/
// Fin test SFML

#include "state.h"

#include <iostream>

using namespace state;

int main(int argc,char* argv[])
{
    //CRÉATION DES PAYS DE L'EUROPE
    Pays EuropeNord(1,EUROPE) ;
    Pays GrandeBretagne(2, EUROPE);
    Pays Islande(3, EUROPE);
    Pays EuropeOccidentale(4, EUROPE);
    Pays EuropeSud(5, EUROPE);
    Pays Scandinavie(6, EUROPE);
    Pays Ukraine(7, EUROPE);

    std::vector<Pays> PaysEurope(7) ;
    PaysEurope[0] = EuropeNord ;
    PaysEurope[1] = GrandeBretagne ;
    PaysEurope[2] = Islande ;
    PaysEurope[3] = EuropeOccidentale ;
    PaysEurope[4] = EuropeSud ;
    PaysEurope[5] = Scandinavie ;
    PaysEurope[6] = Ukraine ;


    //CREATION DES PAYS DE L'OCEANIE
    Pays Indonesie(8, OCEANIE);
    Pays NouvelleGuinee(9, OCEANIE);
    Pays AustralieOuest(10, OCEANIE);
    Pays AustralieEst(11, OCEANIE);

    //CREATION DES PAYS DE L'ASIE
    Pays Inde(12, ASIE);
    Pays Japon(13, ASIE);
    Pays Afghanistan(14, ASIE);
    Pays China(15, ASIE);
    Pays Mongolie(16, ASIE);
    Pays AsieDuSud(17, ASIE);
    Pays Siberie(18, ASIE);
    Pays Oural(19, ASIE);
    Pays Siam(20, ASIE);
    Pays Inde3(21, ASIE);
    Pays Inde4(22, ASIE);
    Pays Inde5(23, ASIE);

    //CREATION DES PAYS DE L'AFRIQUE

    //CREATION DU CONTINENT EUROPE
    Continent Europe(PaysEurope, EUROPE, VERT);

    //TESTS
    std::cout << "ID de l'Europe du Nord : " << EuropeNord.getPaysId() << std::endl;
    std::cout << "isStatic de l'Europe : " << Europe.isStatic() << std::endl ;
    std::cout << "Continent de l'Europe du Nord : " << EuropeNord.getContinentId() << std::endl;
    std::cout << "Continent de l'Europe : " << Europe.getContinentId() << std::endl;


    return 0;
}
