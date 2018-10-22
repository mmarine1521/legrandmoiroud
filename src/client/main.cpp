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
    //Pays EuropeSud(5, EUROPE);
    Pays Scandinavie(6, EUROPE);
    Pays Ukraine(7, EUROPE);

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




    //CREATION Pays
    Pays EuropeSud(5, EUROPE); //int paysId, ContinentId continentId
    std::vector<Pays> FrontaliersEuropeSud(3);
    FrontaliersEuropeSud[0] = EuropeOccidentale;
    FrontaliersEuropeSud[1] = EuropeSud;
    FrontaliersEuropeSud[2] = Ukraine;
    EuropeSud.setPaysFrontaliers(FrontaliersEuropeSud);

    //TESTS Pays
    std::cout << "PAYS" << std::endl;
    std::cout << "isStatic : " << EuropeSud.isStatic() << "  //1" << std::endl;
    std::cout << "TypeId de l'Europe du Sud : " << EuropeSud.getTypeId() << "  //1" << std::endl;
    std::cout << "ID de l'Europe du Sud : " << EuropeSud.getPaysId() << "  //5" << std::endl;
    std::cout << "Continent de l'Europe du Sud : " << EuropeSud.getContinentId() << "  //5" << std::endl << std::endl;
    //std::cout << "Pays Frontaliers de l'Europe du Sud : " << EuropeSud.getPaysFrontaliers() << std::endl;


    //CREATION Continent
    std::vector<Pays> PaysEurope(7) ;
    PaysEurope[0] = EuropeNord ;
    PaysEurope[1] = GrandeBretagne ;
    PaysEurope[2] = Islande ;
    PaysEurope[3] = EuropeOccidentale ;
    PaysEurope[4] = EuropeSud ;
    PaysEurope[5] = Scandinavie ;
    PaysEurope[6] = Ukraine ;
    Continent Europe(PaysEurope, EUROPE, VERT); //std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId

    //TESTS Continent
    std::cout << "CONTINENT" << std::endl;
    std::cout << "isStatic : " << Europe.isStatic() << "  //1" << std::endl;
    std::cout << "TypeId de l'Europe : " << Europe.getTypeId() << "  //2" << std::endl;
    std::cout << "Continent de l'Europe : " << Europe.getContinentId() << "  //5" << std::endl;
    std::cout << "Couleur de l'Europe : " << Europe.getCouleurId() << "  //5" << std::endl << std::endl;
    //std::cout << "Pays de l'Europe : " << Europe.getListePays() << std::endl;


    // CREATION Armee
    Armee armee1(3); //int idJoueur
    armee1.setNombre(20);
    armee1.setPays(EuropeSud);
    armee1.setArmeeStatus(VAINCUE);

    //TESTS Armee
    std::cout << "ARMEE" << std::endl;
    std::cout << "isStatic : " << armee1.isStatic() << "  //0" << std::endl;
    std::cout << "isCarte : " << armee1.isCarte() << "  //0" << std::endl;
    std::cout << "TypeId : " << armee1.getTypeId() << "  //3" << std::endl;
    std::cout << "idJoueur : " << armee1.getIdJoueur() << "  //3" << std::endl;
    std::cout << "nombre : " << armee1.getNombre() << "  //20" << std::endl;
    std::cout << "status : " << armee1.getArmeeStatus() << "  //3" << std::endl << std::endl;
    //std::cout << "pays : " << armee1.getPays() << std::endl;

    //CREATION Carte
    Carte carte1(27, Oural, SOLDAT); //int numero, Pays pays, CarteForce carteForce
    carte1.setCarteId(PIOCHE);
    carte1.setIdJoueur(5);

    //TESTS Carte
    std::cout << "CARTE" << std::endl;
    std::cout << "isStatic : " << carte1.isStatic() << "  //0" << std::endl;
    std::cout << "isCarte : " << carte1.isCarte() << "  //1" << std::endl;
    std::cout << "TypeId : " << carte1.getTypeId() << "  //4" << std::endl;
    std::cout << "CarteId : " << carte1.getCarteId() << "  //2" << std::endl;
    std::cout << "force : " << carte1.getCarteForce() << "  //2" << std::endl;
    std::cout << "idJoueur : " << carte1.getIdJoueur() << "  //5" << std::endl;
    std::cout << "numero : " << carte1.getNumero() << "  //27" << std::endl << std::endl;
    //std::cout << "pays : " << armee1.getPays() << std::endl;


    return 0;
}
