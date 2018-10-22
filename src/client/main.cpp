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

    //CREATION DES PAYS DE L'OCEANIE
    Pays Indonesie(8, OCEANIE);
    Pays NouvelleGuinee(9, OCEANIE);
    Pays AustralieDeLOuest(10, OCEANIE);
    Pays AustralieDeLEst(11, OCEANIE);

    //CREATION DES PAYS DE L'ASIE
    Pays Inde(12, ASIE);
    Pays Japon(13, ASIE);
    Pays Afghanistan(14, ASIE);
    Pays Chine(15, ASIE);
    Pays Mongolie(16, ASIE);
    Pays MoyenOrient(17, ASIE);
    Pays Siberie(18, ASIE);
    Pays Oural(19, ASIE);
    Pays Siam(20, ASIE);
    Pays Yakoutie(21, ASIE);
    Pays Tchita(22, ASIE);
    Pays Kamtchatka(23, ASIE);

    //CREATION DES PAYS DE L'AFRIQUE
    Pays AfriqueDuNord(24, AFRIQUE);
    Pays Egypte(25, AFRIQUE);
    Pays AfriqueDeLEst(26, AFRIQUE);
    Pays Congo(27, AFRIQUE);
    Pays AfriqueDuSud(28, AFRIQUE);
    Pays Madagascar(29, AFRIQUE);

    //CREATION DES PAYS DE L'AMERIQUE DU NORD
    Pays Alaska(30, AMERIQUE_NORD);
    Pays Alberta(31, AMERIQUE_NORD);
    Pays AmeriqueCentrale(32, AMERIQUE_NORD);
    Pays EtatDeLEst(33, AMERIQUE_NORD);
    Pays Groenland(34, AMERIQUE_NORD);
    Pays TerritoireDuNordOuest(35, AMERIQUE_NORD);
    Pays Ontario(36, AMERIQUE_NORD);
    Pays Quebec(37, AMERIQUE_NORD);
    Pays EtatDeLOuest(38, AMERIQUE_NORD);

    //CREATION DES PAYS DE L'AMERIQUE DU SUD
    Pays Argentine(39, AMERIQUE_SUD);
    Pays Bresil(40, AMERIQUE_SUD);
    Pays Perou(41, AMERIQUE_SUD);
    Pays Venezuela(42, AMERIQUE_SUD);


    //CREATION Liste de Pays frontaliers

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


    //CREATION Continent Europe
    std::vector<Pays> PaysEurope(7) ;
    PaysEurope[0] = EuropeNord ;
    PaysEurope[1] = GrandeBretagne ;
    PaysEurope[2] = Islande ;
    PaysEurope[3] = EuropeOccidentale ;
    PaysEurope[4] = EuropeSud ;
    PaysEurope[5] = Scandinavie ;
    PaysEurope[6] = Ukraine ;
    Continent Europe(PaysEurope, EUROPE, VERT); //std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId


    //CREATION Continent Afrique
    std::vector<Pays> PaysAfrique(6) ;
    PaysAfrique[0] = AfriqueDuNord ;
    PaysAfrique[1] = Egypte ;
    PaysAfrique[2] = AfriqueDeLEst ;
    PaysAfrique[3] = Congo ;
    PaysAfrique[4] = AfriqueDuSud ;
    PaysAfrique[5] = Madagascar ;

    Continent Afrique(PaysAfrique, AFRIQUE, MARRON); //std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId

    //CREATION Continent Afrique
    std::vector<Pays> PaysAsie(12) ;
    PaysAsie[0] = MoyenOrient ;
    PaysAsie[1] = Oural ;
    PaysAsie[2] = Afghanistan ;
    PaysAsie[3] = Inde ;
    PaysAsie[4] = Chine ;
    PaysAsie[5] = Mongolie ;
    PaysAsie[6] = Siam ;
    PaysAsie[7] = Siberie ;
    PaysAsie[8] = Japon ;
    PaysAsie[9] = Yakoutie ;
    PaysAsie[10] = Tchita ;
    PaysAsie[11] = Kamtchatka ;

    Continent Asie(PaysAsie, ASIE, ROUGE); //std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId

    //CREATION Continent OCEANIE
    std::vector<Pays> PaysOceanie(4) ;
    PaysOceanie[0] = Indonesie ;
    PaysOceanie[1] = NouvelleGuinee ;
    PaysOceanie[2] = AustralieDeLOuest ;
    PaysOceanie[3] = AustralieDeLEst ;

    Continent Oceanie(PaysOceanie, OCEANIE, VERT_FONCE); //std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId


    //CREATION Continent AMERIQUE DU NORD
    std::vector<Pays> PaysAmeriqueDuNord(9) ;
    PaysAmeriqueDuNord[0] = Alaska ;
    PaysAmeriqueDuNord[1] = Alberta ;
    PaysAmeriqueDuNord[2] = AmeriqueCentrale ;
    PaysAmeriqueDuNord[3] = EtatDeLEst ;
    PaysAmeriqueDuNord[4] = Groenland ;
    PaysAmeriqueDuNord[5] = TerritoireDuNordOuest ;
    PaysAmeriqueDuNord[6] = Ontario ;
    PaysAmeriqueDuNord[7] = Quebec ;
    PaysAmeriqueDuNord[8] = EtatDeLOuest ;

    Continent AmeriqueDuNord(PaysAmeriqueDuNord, AMERIQUE_NORD, JAUNE); //std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId


    //CREATION Continent AMERIQUE DU SUD
    std::vector<Pays> PaysAmeriqueDuSud(4) ;
    PaysAmeriqueDuSud[0] = Argentine ;
    PaysAmeriqueDuSud[1] = Bresil ;
    PaysAmeriqueDuSud[2] = Perou;
    PaysAmeriqueDuSud[3] = Venezuela ;

    Continent AmeriqueDuSud(PaysAmeriqueDuSud, AMERIQUE_SUD, NOIR); //std::vector<Pays> listePays, ContinentId continentId,

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
    Carte carte1(1,GrandeBretagne,CANON);
    Carte carte2(1,Islande ,SOLDAT);
    Carte carte3(1,EuropeOccidentale ,TANK);
    Carte carte4(1,EuropeDuNord ,CANON);
    Carte carte5(1,EuropeDuSud ,TANK);
    Carte carte6(1,Scandinavie ,SOLDAT);
    Carte carte7(1,Ukraine,TANK);
    Carte carte8(1,AfriqueDuNord,CANON);
    Carte carte9(1,Egypte ,SOLDAT);
    Carte carte10(1,AfriqueDeLEst ,SOLDAT);
    Carte carte11(1,Congo ,TANK);
    Carte carte12(1,AfriqueDuSud,SOLDAT);
    Carte carte13(1,Madagascar ,TANK);
    Carte carte14(1,MoyenOrient ,CANON);
    Carte carte15(1,Oural ,TANK);
    Carte carte16(1,Afghanistan ,SOLDAT);
    Carte carte17(1,India ,TANK);
    Carte carte18(1,China ,SOLDAT);
    Carte carte19(1,Mongolie ,CANON);
    Carte carte20(1,Siam ,TANK);
    Carte carte21(1,Siberie ,SOLDAT);
    Carte carte22(1,Japon ,TANK);
    Carte carte23(1,Yakoutie,CANON);
    Carte carte24(1,Tchita ,TANK);
    Carte carte25(1,Kamtchatka ,SOLDAT);
    Carte carte26(1,Indonesie ,TANK);
    Carte carte27(1,NouvelleGuinee ,SOLDAT);
    Carte carte28(1,AustralieDeLEst ,TANK);
    Carte carte29(1,AustralieDeLOuest ,CANON);
    Carte carte30(1,Alaska ,TANK);
    Carte carte31(1,Alberta ,CANON);
    Carte carte32(1,AmeriqueCentrale ,SOLDAT);
    Carte carte33(1,EtatDeLEst ,TANK);
    Carte carte34(1,Groenland ,TANK);
    Carte carte35(1,TerritoireDuNordOuest ,CANON);
    Carte carte36(1,Ontario ,SOLDAT);
    Carte carte37(1,Quebec,TANK);
    Carte carte38(1,EtatsDeLOuest ,CANON);
    Carte carte39(1,Argentine,TANK);
    Carte carte40(1,Bresil ,SOLDAT);
    Carte carte41(1,Perou ,SOLDAT);
    Carte carte42(1,Venezuela ,CANON);

    //carte1.setCarteId(PIOCHE);
   // carte1.setIdJoueur(5);

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
