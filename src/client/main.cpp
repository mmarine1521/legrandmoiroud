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
  //CREATION DES PAYS DE L'AFRIQUE
  Pays Congo(101, AFRIQUE);
  Pays AfriqueDeLEst(102, AFRIQUE);
  Pays Egypte(103, AFRIQUE);
  Pays Madagascar(104, AFRIQUE);
  Pays AfriqueDuNord(105, AFRIQUE);
  Pays AfriqueDuSud(106, AFRIQUE);

  //CREATION DES PAYS DE L'ASIE
  Pays Afghanistan(201, ASIE);
  Pays Chine(202, ASIE);
  Pays Inde(203, ASIE);
  Pays Tchita(204, ASIE);
  Pays Japon(205, ASIE);
  Pays Kamtchatka(206, ASIE);
  Pays MoyenOrient(207, ASIE);
  Pays Mongolie(208, ASIE);
  Pays Siam(209, ASIE);
  Pays Siberie(210, ASIE);
  Pays Oural(211, ASIE);
  Pays Yakoutie(212, ASIE);

  //CREATION DES PAYS DE L'AMERIQUE DU NORD
  Pays Alaska(301, AMERIQUE_NORD);
  Pays Alberta(302, AMERIQUE_NORD);
  Pays AmeriqueCentrale(303, AMERIQUE_NORD);
  Pays EtatsDeLEst(304, AMERIQUE_NORD);
  Pays Groenland(305, AMERIQUE_NORD);
  Pays TerritoiresDuNordOuest(306, AMERIQUE_NORD);
  Pays Ontario(307, AMERIQUE_NORD);
  Pays Quebec(308, AMERIQUE_NORD);
  Pays EtatsDeLOuest(309, AMERIQUE_NORD);

  //CREATION DES PAYS DE L'AMERIQUE DU SUD
  Pays Argentine(401, AMERIQUE_SUD);
  Pays Bresil(402, AMERIQUE_SUD);
  Pays Perou(403, AMERIQUE_SUD);
  Pays Venezuela(404, AMERIQUE_SUD);

  //CRÉATION DES PAYS DE L'EUROPE
  Pays GrandeBretagne(501, EUROPE);
  Pays Islande(502, EUROPE);
  Pays EuropeDuNord(503,EUROPE) ;
  Pays Scandinavie(504, EUROPE);
  Pays EuropeDuSud(505, EUROPE);
  Pays Ukraine(506, EUROPE);
  Pays EuropeOccidentale(507, EUROPE);

  //CREATION DES PAYS DE L'OCEANIE
  Pays AustralieOrientale(601, OCEANIE);
  Pays Indonesie(602, OCEANIE);
  Pays NouvelleGuinee(603, OCEANIE);
  Pays AustralieOccidentale(604, OCEANIE);


    //CREATION Liste de Pays frontaliers
    std::vector<Pays> FrontaliersCongo(3); //101 : 102, 105, 106
    FrontaliersCongo[0] = AfriqueDeLEst;
    FrontaliersCongo[1] = AfriqueDuNord;
    FrontaliersCongo[2] = AfriqueDuSud;
    Congo.setPaysFrontaliers(FrontaliersCongo);

    std::vector<Pays> FrontaliersAfriqueDeLEst(6); //102 : 101, 103, 104, 105, 106, 207
    FrontaliersAfriqueDeLEst[0] = Congo;
    FrontaliersAfriqueDeLEst[1] = Egypte;
    FrontaliersAfriqueDeLEst[2] = Madagascar;
    FrontaliersAfriqueDeLEst[3] = AfriqueDuNord;
    FrontaliersAfriqueDeLEst[4] = AfriqueDuSud;
    FrontaliersAfriqueDeLEst[5] = MoyenOrient;
    AfriqueDeLEst.setPaysFrontaliers(FrontaliersAfriqueDeLEst);

    std::vector<Pays> FrontaliersEgypte(4); //103 : 102, 105, 207, 505
    FrontaliersEgypte[0] = AfriqueDeLEst;
    FrontaliersEgypte[1] = AfriqueDuNord;
    FrontaliersEgypte[2] = MoyenOrient;
    FrontaliersEgypte[3] = EuropeDuSud;
    Egypte.setPaysFrontaliers(FrontaliersEgypte);

    std::vector<Pays> FrontaliersMadagascar(2); //104 : 102, 106
    FrontaliersMadagascar[0] = AfriqueDeLEst;
    FrontaliersMadagascar[1] = AfriqueDuSud;
    Madagascar.setPaysFrontaliers(FrontaliersMadagascar);

    std::vector<Pays> FrontaliersAfriqueDuNord(5); //105 : 101, 102, 103, 402, 507
    FrontaliersAfriqueDuNord[0] = Congo;
    FrontaliersAfriqueDuNord[1] = AfriqueDeLEst;
    FrontaliersAfriqueDuNord[2] = Egypte;
    FrontaliersAfriqueDuNord[3] = Bresil;
    FrontaliersAfriqueDuNord[4] = EuropeOccidentale;
    AfriqueDuNord.setPaysFrontaliers(FrontaliersAfriqueDuNord);

    std::vector<Pays> FrontaliersAfriqueDuSud(3); //106 : 101, 102, 104
    FrontaliersAfriqueDuSud[0] = Congo;
    FrontaliersAfriqueDuSud[1] = AfriqueDeLEst;
    FrontaliersAfriqueDuSud[2] = Madagascar;
    AfriqueDuSud.setPaysFrontaliers(FrontaliersAfriqueDuSud);

    std::vector<Pays> FrontaliersAfghanistan(5); //201 : 202, 203, 207, 211, 506
    FrontaliersAfghanistan[0] = Chine;
    FrontaliersAfghanistan[1] = Inde;
    FrontaliersAfghanistan[2] = MoyenOrient;
    FrontaliersAfghanistan[3] = Oural;
    FrontaliersAfghanistan[4] = Ukraine;
    Afghanistan.setPaysFrontaliers(FrontaliersAfghanistan);

    std::vector<Pays> FrontaliersChine(6); //202 : 201, 203, 208, 209, 210, 211
    FrontaliersChine[0] = Afghanistan;
    FrontaliersChine[1] = Inde;
    FrontaliersChine[2] = Mongolie;
    FrontaliersChine[3] = Siam;
    FrontaliersChine[4] = Siberie;
    FrontaliersChine[5] = Oural;
    Chine.setPaysFrontaliers(FrontaliersChine);

    std::vector<Pays> FrontaliersInde(4); //203 : 201, 202, 207, 209
    FrontaliersInde[0] = Afghanistan;
    FrontaliersInde[1] = Chine;
    FrontaliersInde[2] = MoyenOrient;
    FrontaliersInde[3] = Siam;
    Inde.setPaysFrontaliers(FrontaliersInde);

    std::vector<Pays> FrontaliersTchita(4); //204 : 206, 208, 210, 212
    FrontaliersTchita[0] = Kamtchatka;
    FrontaliersTchita[1] = Mongolie;
    FrontaliersTchita[2] = Siberie;
    FrontaliersTchita[3] = Yakoutie;
    Tchita.setPaysFrontaliers(FrontaliersTchita);

    std::vector<Pays> FrontaliersJapon(2); //205 : 206, 208
    FrontaliersTchita[0] = Kamtchatka;
    FrontaliersTchita[1] = Mongolie;
    Japon.setPaysFrontaliers(FrontaliersJapon);

    std::vector<Pays> FrontaliersKamtchatka(5); //206 : 204, 205, 208, 212, 301
    FrontaliersKamtchatka[0] = Tchita;
    FrontaliersKamtchatka[1] = Japon;
    FrontaliersKamtchatka[2] = Mongolie;
    FrontaliersKamtchatka[3] = Yakoutie;
    FrontaliersKamtchatka[4] = Alaska;
    Kamtchatka.setPaysFrontaliers(FrontaliersKamtchatka);

    std::vector<Pays> FrontaliersMoyenOrient(6); //207 : 102, 103, 201, 203, 505, 506
    FrontaliersMoyenOrient[0] = AfriqueDeLEst;
    FrontaliersMoyenOrient[1] = Egypte;
    FrontaliersMoyenOrient[2] = Afghanistan;
    FrontaliersMoyenOrient[3] = Inde;
    FrontaliersMoyenOrient[4] = EuropeDuSud;
    FrontaliersMoyenOrient[5] = Ukraine;
    MoyenOrient.setPaysFrontaliers(FrontaliersMoyenOrient);

    std::vector<Pays> FrontaliersMongolie(5); //208 : 202, 204, 205, 206, 210
    FrontaliersMongolie[0] = Chine;
    FrontaliersMongolie[1] = Tchita;
    FrontaliersMongolie[2] = Japon;
    FrontaliersMongolie[3] = Kamtchatka;
    FrontaliersMongolie[4] = Siberie;
    Mongolie.setPaysFrontaliers(FrontaliersMongolie);

    std::vector<Pays> FrontaliersSiam(3); //209 : 202, 203, 602
    FrontaliersSiam[0] = Chine;
    FrontaliersSiam[1] = Inde;
    FrontaliersSiam[2] = Indonesie;
    Siam.setPaysFrontaliers(FrontaliersSiam);

    std::vector<Pays> FrontaliersSiberie(5); //210 : 202, 204, 208, 211, 212
    FrontaliersSiberie[0] = Chine;
    FrontaliersSiberie[1] = Tchita;
    FrontaliersSiberie[2] = Mongolie;
    FrontaliersSiberie[3] = Oural;
    FrontaliersSiberie[4] = Yakoutie;
    Siberie.setPaysFrontaliers(FrontaliersSiberie);

    std::vector<Pays> FrontaliersOural(4); //211 : 201, 202, 210, 506
    FrontaliersOural[0] = Afghanistan;
    FrontaliersOural[1] = Chine;
    FrontaliersOural[2] = Siberie;
    FrontaliersOural[3] = Ukraine;
    Oural.setPaysFrontaliers(FrontaliersOural);

    std::vector<Pays> FrontaliersYakoutie(3); //212 : 204, 206, 210
    FrontaliersYakoutie[0] = Tchita;
    FrontaliersYakoutie[1] = Kamtchatka;
    FrontaliersYakoutie[2] = Siberie;
    Yakoutie.setPaysFrontaliers(FrontaliersYakoutie);

    std::vector<Pays> FrontaliersAlaska(3); //301 : 206, 302, 306
    FrontaliersAlaska[0] = Kamtchatka;
    FrontaliersAlaska[1] = Alberta;
    FrontaliersAlaska[2] = TerritoiresDuNordOuest;
    Alaska.setPaysFrontaliers(FrontaliersAlaska);

    std::vector<Pays> FrontaliersAlberta(4); //302 : 301, 306, 307, 309
    FrontaliersAlberta[0] = Alaska;
    FrontaliersAlberta[1] = TerritoiresDuNordOuest;
    FrontaliersAlberta[2] = Ontario;
    FrontaliersAlberta[3] = EtatsDeLOuest;
    Alberta.setPaysFrontaliers(FrontaliersAlberta);

    std::vector<Pays> FrontaliersAmeriqueCentrale(3); //303 : 304, 309, 404
    FrontaliersAmeriqueCentrale[0] = EtatsDeLEst;
    FrontaliersAmeriqueCentrale[1] = EtatsDeLOuest;
    FrontaliersAmeriqueCentrale[2] = Venezuela;
    AmeriqueCentrale.setPaysFrontaliers(FrontaliersAmeriqueCentrale);

    std::vector<Pays> FrontaliersEtatsDeLEst(4); //304 : 303, 307, 308, 309
    FrontaliersEtatsDeLEst[0] = AmeriqueCentrale;
    FrontaliersEtatsDeLEst[1] = Ontario;
    FrontaliersEtatsDeLEst[2] = Quebec;
    FrontaliersEtatsDeLEst[3] = EtatsDeLOuest;
    EtatsDeLEst.setPaysFrontaliers(FrontaliersEtatsDeLEst);

    std::vector<Pays> FrontaliersGroenland(4); //305 : 306, 307, 308, 502
    FrontaliersGroenland[0] = TerritoiresDuNordOuest;
    FrontaliersGroenland[1] = Ontario;
    FrontaliersGroenland[2] = Quebec;
    FrontaliersGroenland[3] = Islande;
    Groenland.setPaysFrontaliers(FrontaliersGroenland);

    std::vector<Pays> FrontaliersTerritoiresDuNordOuest(4); //306 : 301, 302, 305, 307
    FrontaliersTerritoiresDuNordOuest[0] = Alaska;
    FrontaliersTerritoiresDuNordOuest[1] = Alberta;
    FrontaliersTerritoiresDuNordOuest[2] = Groenland;
    FrontaliersTerritoiresDuNordOuest[3] = Ontario;
    TerritoiresDuNordOuest.setPaysFrontaliers(FrontaliersTerritoiresDuNordOuest);

    std::vector<Pays> FrontaliersOntario(6); //307 : 302, 304, 305, 306, 308, 309
    FrontaliersOntario[0] = Alberta;
    FrontaliersOntario[1] = EtatsDeLEst;
    FrontaliersOntario[2] = Groenland;
    FrontaliersOntario[3] = TerritoiresDuNordOuest;
    FrontaliersOntario[4] = Quebec;
    FrontaliersOntario[5] = EtatsDeLOuest;
    Ontario.setPaysFrontaliers(FrontaliersOntario);

    std::vector<Pays> FrontaliersQuebec(3); //308 : 304, 305, 307
    FrontaliersQuebec[0] = EtatsDeLEst;
    FrontaliersQuebec[1] = Groenland;
    FrontaliersQuebec[2] = Ontario;
    Quebec.setPaysFrontaliers(FrontaliersQuebec);

    std::vector<Pays> FrontaliersEtatsDeLOuest(4); //309 : 302, 303, 304, 307
    FrontaliersEtatsDeLOuest[0] = Alberta;
    FrontaliersEtatsDeLOuest[1] = AmeriqueCentrale;
    FrontaliersEtatsDeLOuest[2] = EtatsDeLEst;
    FrontaliersEtatsDeLOuest[3] = Ontario;
    EtatsDeLOuest.setPaysFrontaliers(FrontaliersEtatsDeLOuest);

    std::vector<Pays> FrontaliersArgentine(2); //401 : 402, 403
    FrontaliersArgentine[0] = Bresil;
    FrontaliersArgentine[1] = Perou;
    Argentine.setPaysFrontaliers(FrontaliersArgentine);

    std::vector<Pays> FrontaliersBresil(4); //402 : 105, 401, 403, 404
    FrontaliersBresil[0] = AfriqueDuNord;
    FrontaliersBresil[1] = Argentine;
    FrontaliersBresil[2] = Perou;
    FrontaliersBresil[3] = Venezuela;
    Bresil.setPaysFrontaliers(FrontaliersBresil);

    std::vector<Pays> FrontaliersPerou(3); //403 : 401, 402, 404
    FrontaliersPerou[0] = Argentine;
    FrontaliersPerou[1] = Bresil;
    FrontaliersPerou[2] = Venezuela;
    Perou.setPaysFrontaliers(FrontaliersPerou);

    std::vector<Pays> FrontaliersVenezuela(3); //404 : 303, 402, 403
    FrontaliersVenezuela[0] = AmeriqueCentrale;
    FrontaliersVenezuela[1] = Bresil;
    FrontaliersVenezuela[2] = Perou;
    Venezuela.setPaysFrontaliers(FrontaliersVenezuela);

    std::vector<Pays> FrontaliersGrandeBretagne(4); //501 : 502, 503, 504, 507
    FrontaliersGrandeBretagne[0] = Islande;
    FrontaliersGrandeBretagne[1] = EuropeDuNord;
    FrontaliersGrandeBretagne[2] = Scandinavie;
    FrontaliersGrandeBretagne[3] = EuropeOccidentale;
    GrandeBretagne.setPaysFrontaliers(FrontaliersGrandeBretagne);

    std::vector<Pays> FrontaliersIslande(3); //502 : 305, 501, 504
    FrontaliersIslande[0] = Groenland;
    FrontaliersIslande[1] = GrandeBretagne;
    FrontaliersIslande[2] = Scandinavie;
    Islande.setPaysFrontaliers(FrontaliersIslande);

    std::vector<Pays> FrontaliersEuropeDuNord(5); //503 : 501, 504, 505, 506, 507
    FrontaliersEuropeDuNord[0] = GrandeBretagne;
    FrontaliersEuropeDuNord[1] = Scandinavie;
    FrontaliersEuropeDuNord[2] = EuropeDuSud;
    FrontaliersEuropeDuNord[3] = Ukraine;
    FrontaliersEuropeDuNord[4] = EuropeOccidentale;
    EuropeDuNord.setPaysFrontaliers(FrontaliersEuropeDuNord);

    std::vector<Pays> FrontaliersScandinavie(4); //504 : 501, 502, 503, 506
    FrontaliersScandinavie[0] = GrandeBretagne;
    FrontaliersScandinavie[1] = Islande;
    FrontaliersScandinavie[2] = EuropeDuNord;
    FrontaliersScandinavie[3] = Ukraine;
    Scandinavie.setPaysFrontaliers(FrontaliersScandinavie);

    std::vector<Pays> FrontaliersEuropeDuSud(5); //505 : 103, 207, 503, 506, 507
    FrontaliersEuropeDuSud[0] = Egypte;
    FrontaliersEuropeDuSud[1] = MoyenOrient;
    FrontaliersEuropeDuSud[2] = EuropeDuNord;
    FrontaliersEuropeDuSud[3] = Ukraine;
    FrontaliersEuropeDuSud[4] = EuropeOccidentale;
    EuropeDuSud.setPaysFrontaliers(FrontaliersEuropeDuSud);

    std::vector<Pays> FrontaliersUkraine(6); //506 : 201, 207, 211, 503, 504, 505
    FrontaliersUkraine[0] = Afghanistan;
    FrontaliersUkraine[1] = MoyenOrient;
    FrontaliersUkraine[2] = Oural;
    FrontaliersUkraine[3] = EuropeDuNord;
    FrontaliersUkraine[4] = Scandinavie;
    FrontaliersUkraine[5] = EuropeDuSud;
    Ukraine.setPaysFrontaliers(FrontaliersUkraine);

    std::vector<Pays> FrontaliersEuropeOccidentale(4); //507 : 105, 501, 503, 504
    FrontaliersEuropeOccidentale[0] = AfriqueDuNord;
    FrontaliersEuropeOccidentale[1] = GrandeBretagne;
    FrontaliersEuropeOccidentale[2] = EuropeDuNord;
    FrontaliersEuropeOccidentale[3] = Scandinavie;
    EuropeOccidentale.setPaysFrontaliers(FrontaliersEuropeOccidentale);

    std::vector<Pays> FrontaliersAustralieOrientale(2); //601 : 603, 604
    FrontaliersAustralieOrientale[0] = NouvelleGuinee;
    FrontaliersAustralieOrientale[1] = AustralieOccidentale;
    AustralieOrientale.setPaysFrontaliers(FrontaliersAustralieOrientale);

    std::vector<Pays> FrontaliersIndonesie(3); //602 : 209, 603, 604
    FrontaliersIndonesie[0] = Siam;
    FrontaliersIndonesie[1] = NouvelleGuinee;
    FrontaliersIndonesie[2] = AustralieOccidentale;
    Indonesie.setPaysFrontaliers(FrontaliersIndonesie);

    std::vector<Pays> FrontaliersNouvelleGuinee(3); //603 : 601, 602, 604
    FrontaliersNouvelleGuinee[0] = AustralieOrientale;
    FrontaliersNouvelleGuinee[1] = Indonesie;
    FrontaliersNouvelleGuinee[2] = AustralieOccidentale;
    NouvelleGuinee.setPaysFrontaliers(FrontaliersNouvelleGuinee);

    std::vector<Pays> FrontaliersAustralieOccidentale(3); //604 : 601, 602, 603
    FrontaliersAustralieOccidentale[0] = AustralieOrientale;
    FrontaliersAustralieOccidentale[1] = Indonesie;
    FrontaliersAustralieOccidentale[2] = NouvelleGuinee;
    AustralieOccidentale.setPaysFrontaliers(FrontaliersAustralieOccidentale);

    //TESTS Pays
    std::cout << "PAYS" << std::endl;
    std::cout << "isStatic : " << EuropeDuSud.isStatic() << "  //1" << std::endl;
    std::cout << "TypeId de l'Europe du Sud : " << EuropeDuSud.getTypeId() << "  //1" << std::endl;
    std::cout << "ID de l'Europe du Sud : " << EuropeDuSud.getPaysId() << "  //505" << std::endl;
    std::cout << "Continent de l'Europe du Sud : " << EuropeDuSud.getContinentId() << "  //5" << std::endl << std::endl;
    //std::cout << "Pays Frontaliers de l'Europe du Sud : " << EuropeDuSud.getPaysFrontaliers() << std::endl;


    //CREATION Continent Europe
    std::vector<Pays> PaysEurope(7) ;
    PaysEurope[0] = EuropeDuNord ;
    PaysEurope[1] = GrandeBretagne ;
    PaysEurope[2] = Islande ;
    PaysEurope[3] = EuropeOccidentale ;
    PaysEurope[4] = EuropeDuSud ;
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
    PaysOceanie[2] = AustralieOccidentale ;
    PaysOceanie[3] = AustralieOrientale ;

    Continent Oceanie(PaysOceanie, OCEANIE, VERT_FONCE); //std::vector<Pays> listePays, ContinentId continentId, CouleurId couleurId


    //CREATION Continent AMERIQUE DU NORD
    std::vector<Pays> PaysAmeriqueDuNord(9) ;
    PaysAmeriqueDuNord[0] = Alaska ;
    PaysAmeriqueDuNord[1] = Alberta ;
    PaysAmeriqueDuNord[2] = AmeriqueCentrale ;
    PaysAmeriqueDuNord[3] = EtatsDeLEst ;
    PaysAmeriqueDuNord[4] = Groenland ;
    PaysAmeriqueDuNord[5] = TerritoiresDuNordOuest ;
    PaysAmeriqueDuNord[6] = Ontario ;
    PaysAmeriqueDuNord[7] = Quebec ;
    PaysAmeriqueDuNord[8] = EtatsDeLOuest ;

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
    armee1.setPays(EuropeDuSud);
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
    Carte carte2(2,Islande ,SOLDAT);
    Carte carte3(3,EuropeOccidentale ,TANK);
    Carte carte4(4,EuropeDuNord ,CANON);
    Carte carte5(5,EuropeDuSud ,TANK);
    Carte carte6(6,Scandinavie ,SOLDAT);
    Carte carte7(7,Ukraine,TANK);
    Carte carte8(8,AfriqueDuNord,CANON);
    Carte carte9(9,Egypte ,SOLDAT);
    Carte carte10(10,AfriqueDeLEst ,SOLDAT);
    Carte carte11(11,Congo ,TANK);
    Carte carte12(12,AfriqueDuSud,SOLDAT);
    Carte carte13(13,Madagascar ,TANK);
    Carte carte14(14,MoyenOrient ,CANON);
    Carte carte15(15,Oural ,TANK);
    Carte carte16(16,Afghanistan ,SOLDAT);
    Carte carte17(17,Inde ,TANK);
    Carte carte18(18,Chine ,SOLDAT);
    Carte carte19(19,Mongolie ,CANON);
    Carte carte20(20,Siam ,TANK);
    Carte carte21(21,Siberie ,SOLDAT);
    Carte carte22(22,Japon ,TANK);
    Carte carte23(23,Yakoutie,CANON);
    Carte carte24(24,Tchita ,TANK);
    Carte carte25(25,Kamtchatka ,SOLDAT);
    Carte carte26(26,Indonesie ,TANK);
    Carte carte27(27,NouvelleGuinee ,SOLDAT);
    Carte carte28(28,AustralieOrientale ,TANK);
    Carte carte29(29,AustralieOccidentale ,CANON);
    Carte carte30(30,Alaska ,TANK);
    Carte carte31(31,Alberta ,CANON);
    Carte carte32(32,AmeriqueCentrale ,SOLDAT);
    Carte carte33(33,EtatsDeLEst ,TANK);
    Carte carte34(34,Groenland ,TANK);
    Carte carte35(35,TerritoiresDuNordOuest ,CANON);
    Carte carte36(36,Ontario ,SOLDAT);
    Carte carte37(37,Quebec,TANK);
    Carte carte38(38,EtatsDeLOuest ,CANON);
    Carte carte39(39,Argentine,TANK);
    Carte carte40(40,Bresil ,SOLDAT);
    Carte carte41(41,Perou ,SOLDAT);
    Carte carte42(42,Venezuela ,CANON);

    carte1.setCarteId(PIOCHE);
    carte1.setIdJoueur(5);

    //TESTS Carte
    std::cout << "CARTE" << std::endl;
    std::cout << "isStatic : " << carte1.isStatic() << "  //0" << std::endl;
    std::cout << "isCarte : " << carte1.isCarte() << "  //1" << std::endl;
    std::cout << "TypeId : " << carte1.getTypeId() << "  //4" << std::endl;
    std::cout << "CarteId : " << carte1.getCarteId() << "  //2" << std::endl;
    std::cout << "force : " << carte1.getCarteForce() << "  //1" << std::endl;
    std::cout << "idJoueur : " << carte1.getIdJoueur() << "  //5" << std::endl;
    std::cout << "numero : " << carte1.getNumero() << "  //1" << std::endl << std::endl;
    //std::cout << "pays : " << armee1.getPays() << std::endl;


    return 0;
}
