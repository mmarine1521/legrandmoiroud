#include "CreationStaticElements.h"

#include <vector>

namespace engine {

CreationStaticElements::~CreationStaticElements (){
}

IdCommande const CreationStaticElements::getIdCommande (){
  return CREASTATIC;
}

/*std::map<std::string, state::Pays> creationPays (){
  //CREATION DES PAYS DE L'AFRIQUE
  state::Pays Congo("Congo", 101, AFRIQUE);
  state::Pays AfriqueDeLEst("Afrique De L'Est", 102, AFRIQUE);
  state::Pays Egypte("Egypte", 103, AFRIQUE);
  state::Pays Madagascar("Madagascar", 104, AFRIQUE);
  state::Pays AfriqueDuNord("Afrique Du Nord", 105, AFRIQUE);
  state::Pays AfriqueDuSud("Afrique Du Sud", 106, AFRIQUE);

  //CREATION DES PAYS DE L'ASIE
  state::Pays Afghanistan("Afghanistan", 201, ASIE);
  state::Pays Chine("Chine", 202, ASIE);
  state::Pays Inde("Inde", 203, ASIE);
  state::Pays Tchita("Tchita", 204, ASIE);
  state::Pays Japon("Japon", 205, ASIE);
  state::Pays Kamtchatka("Kamtchatka", 206, ASIE);
  state::Pays MoyenOrient("Moyen Orient", 207, ASIE);
  state::Pays Mongolie("Mongolie", 208, ASIE);
  state::Pays Siam("Siam", 209, ASIE);
  state::Pays Siberie("Siberie", 210, ASIE);
  state::Pays Oural("Oural", 211, ASIE);
  state::Pays Yakoutie("Yakoutie", 212, ASIE);

  //CREATION DES PAYS DE L'AMERIQUE DU NORD
  state::Pays Alaska("Alaska", 301, AMERIQUE_NORD);
  state::Pays Alberta("Alberta", 302, AMERIQUE_NORD);
  state::Pays AmeriqueCentrale("Amerique Centrale", 303, AMERIQUE_NORD);
  state::Pays EtatsDeLEst("Etats De L'Est", 304, AMERIQUE_NORD);
  state::Pays Groenland("Groenland", 305, AMERIQUE_NORD);
  state::Pays TerritoiresDuNordOuest("Territoires Du Nord-Ouest", 306, AMERIQUE_NORD);
  state::Pays Ontario("Ontario", 307, AMERIQUE_NORD);
  state::Pays Quebec("Québec", 308, AMERIQUE_NORD);
  state::Pays EtatsDeLOuest("Etats De L'Ouest", 309, AMERIQUE_NORD);

  //CREATION DES PAYS DE L'AMERIQUE DU SUD
  state::Pays Argentine("Argentine", 401, AMERIQUE_SUD);
  state::Pays Bresil("Brésil", 402, AMERIQUE_SUD);
  state::Pays Perou("Pérou", 403, AMERIQUE_SUD);
  state::Pays Venezuela("Vénézuela", 404, AMERIQUE_SUD);

  //CRÉATION DES PAYS DE L'EUROPE
  state::Pays GrandeBretagne("Grande Bretagne", 501, EUROPE);
  state::Pays Islande("Islande", 502, EUROPE);
  state::Pays EuropeDuNord("Europe Du Nord", 503,EUROPE) ;
  state::Pays Scandinavie("Scandinavie", 504, EUROPE);
  state::Pays EuropeDuSud("Europe Du Sud", 505, EUROPE);
  state::Pays Ukraine("Ukraine", 506, EUROPE);
  state::Pays EuropeOccidentale("Europe Occidentale", 507, EUROPE);

  //CREATION DES PAYS DE L'OCEANIE
  state::Pays AustralieOrientale("Australie Orientale", 601, OCEANIE);
  state::Pays Indonesie("Indonesie", 602, OCEANIE);
  state::Pays NouvelleGuinee("Nouvelle Guinée", 603, OCEANIE);
  state::Pays AustralieOccidentale("Australie Occidentale", 604, OCEANIE);


    //CREATION Liste de state::Pays frontaliers
    std::vector<state::Pays> FrontaliersCongo(3); //101 : 102, 105, 106
    FrontaliersCongo[0] = AfriqueDeLEst;
    FrontaliersCongo[1] = AfriqueDuNord;
    FrontaliersCongo[2] = AfriqueDuSud;
    Congo.setPaysFrontaliers(FrontaliersCongo);

    std::vector<state::Pays> FrontaliersAfriqueDeLEst(6); //102 : 101, 103, 104, 105, 106, 207
    FrontaliersAfriqueDeLEst[0] = Congo;
    FrontaliersAfriqueDeLEst[1] = Egypte;
    FrontaliersAfriqueDeLEst[2] = Madagascar;
    FrontaliersAfriqueDeLEst[3] = AfriqueDuNord;
    FrontaliersAfriqueDeLEst[4] = AfriqueDuSud;
    FrontaliersAfriqueDeLEst[5] = MoyenOrient;
    AfriqueDeLEst.setPaysFrontaliers(FrontaliersAfriqueDeLEst);

    std::vector<state::Pays> FrontaliersEgypte(4); //103 : 102, 105, 207, 505
    FrontaliersEgypte[0] = AfriqueDeLEst;
    FrontaliersEgypte[1] = AfriqueDuNord;
    FrontaliersEgypte[2] = MoyenOrient;
    FrontaliersEgypte[3] = EuropeDuSud;
    Egypte.setPaysFrontaliers(FrontaliersEgypte);

    std::vector<state::Pays> FrontaliersMadagascar(2); //104 : 102, 106
    FrontaliersMadagascar[0] = AfriqueDeLEst;
    FrontaliersMadagascar[1] = AfriqueDuSud;
    Madagascar.setPaysFrontaliers(FrontaliersMadagascar);

    std::vector<state::Pays> FrontaliersAfriqueDuNord(5); //105 : 101, 102, 103, 402, 507
    FrontaliersAfriqueDuNord[0] = Congo;
    FrontaliersAfriqueDuNord[1] = AfriqueDeLEst;
    FrontaliersAfriqueDuNord[2] = Egypte;
    FrontaliersAfriqueDuNord[3] = Bresil;
    FrontaliersAfriqueDuNord[4] = EuropeOccidentale;
    AfriqueDuNord.setPaysFrontaliers(FrontaliersAfriqueDuNord);

    std::vector<state::Pays> FrontaliersAfriqueDuSud(3); //106 : 101, 102, 104
    FrontaliersAfriqueDuSud[0] = Congo;
    FrontaliersAfriqueDuSud[1] = AfriqueDeLEst;
    FrontaliersAfriqueDuSud[2] = Madagascar;
    AfriqueDuSud.setPaysFrontaliers(FrontaliersAfriqueDuSud);

    std::vector<state::Pays> FrontaliersAfghanistan(5); //201 : 202, 203, 207, 211, 506
    FrontaliersAfghanistan[0] = Chine;
    FrontaliersAfghanistan[1] = Inde;
    FrontaliersAfghanistan[2] = MoyenOrient;
    FrontaliersAfghanistan[3] = Oural;
    FrontaliersAfghanistan[4] = Ukraine;
    Afghanistan.setPaysFrontaliers(FrontaliersAfghanistan);

    std::vector<state::Pays> FrontaliersChine(6); //202 : 201, 203, 208, 209, 210, 211
    FrontaliersChine[0] = Afghanistan;
    FrontaliersChine[1] = Inde;
    FrontaliersChine[2] = Mongolie;
    FrontaliersChine[3] = Siam;
    FrontaliersChine[4] = Siberie;
    FrontaliersChine[5] = Oural;
    Chine.setPaysFrontaliers(FrontaliersChine);

    std::vector<state::Pays> FrontaliersInde(4); //203 : 201, 202, 207, 209
    FrontaliersInde[0] = Afghanistan;
    FrontaliersInde[1] = Chine;
    FrontaliersInde[2] = MoyenOrient;
    FrontaliersInde[3] = Siam;
    Inde.setPaysFrontaliers(FrontaliersInde);

    std::vector<state::Pays> FrontaliersTchita(4); //204 : 206, 208, 210, 212
    FrontaliersTchita[0] = Kamtchatka;
    FrontaliersTchita[1] = Mongolie;
    FrontaliersTchita[2] = Siberie;
    FrontaliersTchita[3] = Yakoutie;
    Tchita.setPaysFrontaliers(FrontaliersTchita);

    std::vector<state::Pays> FrontaliersJapon(2); //205 : 206, 208
    FrontaliersTchita[0] = Kamtchatka;
    FrontaliersTchita[1] = Mongolie;
    Japon.setPaysFrontaliers(FrontaliersJapon);

    std::vector<state::Pays> FrontaliersKamtchatka(5); //206 : 204, 205, 208, 212, 301
    FrontaliersKamtchatka[0] = Tchita;
    FrontaliersKamtchatka[1] = Japon;
    FrontaliersKamtchatka[2] = Mongolie;
    FrontaliersKamtchatka[3] = Yakoutie;
    FrontaliersKamtchatka[4] = Alaska;
    Kamtchatka.setPaysFrontaliers(FrontaliersKamtchatka);

    std::vector<state::Pays> FrontaliersMoyenOrient(6); //207 : 102, 103, 201, 203, 505, 506
    FrontaliersMoyenOrient[0] = AfriqueDeLEst;
    FrontaliersMoyenOrient[1] = Egypte;
    FrontaliersMoyenOrient[2] = Afghanistan;
    FrontaliersMoyenOrient[3] = Inde;
    FrontaliersMoyenOrient[4] = EuropeDuSud;
    FrontaliersMoyenOrient[5] = Ukraine;
    MoyenOrient.setPaysFrontaliers(FrontaliersMoyenOrient);

    std::vector<state::Pays> FrontaliersMongolie(5); //208 : 202, 204, 205, 206, 210
    FrontaliersMongolie[0] = Chine;
    FrontaliersMongolie[1] = Tchita;
    FrontaliersMongolie[2] = Japon;
    FrontaliersMongolie[3] = Kamtchatka;
    FrontaliersMongolie[4] = Siberie;
    Mongolie.setPaysFrontaliers(FrontaliersMongolie);

    std::vector<state::Pays> FrontaliersSiam(3); //209 : 202, 203, 602
    FrontaliersSiam[0] = Chine;
    FrontaliersSiam[1] = Inde;
    FrontaliersSiam[2] = Indonesie;
    Siam.setPaysFrontaliers(FrontaliersSiam);

    std::vector<state::Pays> FrontaliersSiberie(5); //210 : 202, 204, 208, 211, 212
    FrontaliersSiberie[0] = Chine;
    FrontaliersSiberie[1] = Tchita;
    FrontaliersSiberie[2] = Mongolie;
    FrontaliersSiberie[3] = Oural;
    FrontaliersSiberie[4] = Yakoutie;
    Siberie.setPaysFrontaliers(FrontaliersSiberie);

    std::vector<state::Pays> FrontaliersOural(4); //211 : 201, 202, 210, 506
    FrontaliersOural[0] = Afghanistan;
    FrontaliersOural[1] = Chine;
    FrontaliersOural[2] = Siberie;
    FrontaliersOural[3] = Ukraine;
    Oural.setPaysFrontaliers(FrontaliersOural);

    std::vector<state::Pays> FrontaliersYakoutie(3); //212 : 204, 206, 210
    FrontaliersYakoutie[0] = Tchita;
    FrontaliersYakoutie[1] = Kamtchatka;
    FrontaliersYakoutie[2] = Siberie;
    Yakoutie.setPaysFrontaliers(FrontaliersYakoutie);

    std::vector<state::Pays> FrontaliersAlaska(3); //301 : 206, 302, 306
    FrontaliersAlaska[0] = Kamtchatka;
    FrontaliersAlaska[1] = Alberta;
    FrontaliersAlaska[2] = TerritoiresDuNordOuest;
    Alaska.setPaysFrontaliers(FrontaliersAlaska);

    std::vector<state::Pays> FrontaliersAlberta(4); //302 : 301, 306, 307, 309
    FrontaliersAlberta[0] = Alaska;
    FrontaliersAlberta[1] = TerritoiresDuNordOuest;
    FrontaliersAlberta[2] = Ontario;
    FrontaliersAlberta[3] = EtatsDeLOuest;
    Alberta.setPaysFrontaliers(FrontaliersAlberta);

    std::vector<state::Pays> FrontaliersAmeriqueCentrale(3); //303 : 304, 309, 404
    FrontaliersAmeriqueCentrale[0] = EtatsDeLEst;
    FrontaliersAmeriqueCentrale[1] = EtatsDeLOuest;
    FrontaliersAmeriqueCentrale[2] = Venezuela;
    AmeriqueCentrale.setPaysFrontaliers(FrontaliersAmeriqueCentrale);

    std::vector<state::Pays> FrontaliersEtatsDeLEst(4); //304 : 303, 307, 308, 309
    FrontaliersEtatsDeLEst[0] = AmeriqueCentrale;
    FrontaliersEtatsDeLEst[1] = Ontario;
    FrontaliersEtatsDeLEst[2] = Quebec;
    FrontaliersEtatsDeLEst[3] = EtatsDeLOuest;
    EtatsDeLEst.setPaysFrontaliers(FrontaliersEtatsDeLEst);

    std::vector<state::Pays> FrontaliersGroenland(4); //305 : 306, 307, 308, 502
    FrontaliersGroenland[0] = TerritoiresDuNordOuest;
    FrontaliersGroenland[1] = Ontario;
    FrontaliersGroenland[2] = Quebec;
    FrontaliersGroenland[3] = Islande;
    Groenland.setPaysFrontaliers(FrontaliersGroenland);

    std::vector<state::Pays> FrontaliersTerritoiresDuNordOuest(4); //306 : 301, 302, 305, 307
    FrontaliersTerritoiresDuNordOuest[0] = Alaska;
    FrontaliersTerritoiresDuNordOuest[1] = Alberta;
    FrontaliersTerritoiresDuNordOuest[2] = Groenland;
    FrontaliersTerritoiresDuNordOuest[3] = Ontario;
    TerritoiresDuNordOuest.setPaysFrontaliers(FrontaliersTerritoiresDuNordOuest);

    std::vector<state::Pays> FrontaliersOntario(6); //307 : 302, 304, 305, 306, 308, 309
    FrontaliersOntario[0] = Alberta;
    FrontaliersOntario[1] = EtatsDeLEst;
    FrontaliersOntario[2] = Groenland;
    FrontaliersOntario[3] = TerritoiresDuNordOuest;
    FrontaliersOntario[4] = Quebec;
    FrontaliersOntario[5] = EtatsDeLOuest;
    Ontario.setPaysFrontaliers(FrontaliersOntario);

    std::vector<state::Pays> FrontaliersQuebec(3); //308 : 304, 305, 307
    FrontaliersQuebec[0] = EtatsDeLEst;
    FrontaliersQuebec[1] = Groenland;
    FrontaliersQuebec[2] = Ontario;
    Quebec.setPaysFrontaliers(FrontaliersQuebec);

    std::vector<state::Pays> FrontaliersEtatsDeLOuest(4); //309 : 302, 303, 304, 307
    FrontaliersEtatsDeLOuest[0] = Alberta;
    FrontaliersEtatsDeLOuest[1] = AmeriqueCentrale;
    FrontaliersEtatsDeLOuest[2] = EtatsDeLEst;
    FrontaliersEtatsDeLOuest[3] = Ontario;
    EtatsDeLOuest.setPaysFrontaliers(FrontaliersEtatsDeLOuest);

    std::vector<state::Pays> FrontaliersArgentine(2); //401 : 402, 403
    FrontaliersArgentine[0] = Bresil;
    FrontaliersArgentine[1] = Perou;
    Argentine.setPaysFrontaliers(FrontaliersArgentine);

    std::vector<state::Pays> FrontaliersBresil(4); //402 : 105, 401, 403, 404
    FrontaliersBresil[0] = AfriqueDuNord;
    FrontaliersBresil[1] = Argentine;
    FrontaliersBresil[2] = Perou;
    FrontaliersBresil[3] = Venezuela;
    Bresil.setPaysFrontaliers(FrontaliersBresil);

    std::vector<state::Pays> FrontaliersPerou(3); //403 : 401, 402, 404
    FrontaliersPerou[0] = Argentine;
    FrontaliersPerou[1] = Bresil;
    FrontaliersPerou[2] = Venezuela;
    Perou.setPaysFrontaliers(FrontaliersPerou);

    std::vector<state::Pays> FrontaliersVenezuela(3); //404 : 303, 402, 403
    FrontaliersVenezuela[0] = AmeriqueCentrale;
    FrontaliersVenezuela[1] = Bresil;
    FrontaliersVenezuela[2] = Perou;
    Venezuela.setPaysFrontaliers(FrontaliersVenezuela);

    std::vector<state::Pays> FrontaliersGrandeBretagne(4); //501 : 502, 503, 504, 507
    FrontaliersGrandeBretagne[0] = Islande;
    FrontaliersGrandeBretagne[1] = EuropeDuNord;
    FrontaliersGrandeBretagne[2] = Scandinavie;
    FrontaliersGrandeBretagne[3] = EuropeOccidentale;
    GrandeBretagne.setPaysFrontaliers(FrontaliersGrandeBretagne);

    std::vector<state::Pays> FrontaliersIslande(3); //502 : 305, 501, 504
    FrontaliersIslande[0] = Groenland;
    FrontaliersIslande[1] = GrandeBretagne;
    FrontaliersIslande[2] = Scandinavie;
    Islande.setPaysFrontaliers(FrontaliersIslande);

    std::vector<state::Pays> FrontaliersEuropeDuNord(5); //503 : 501, 504, 505, 506, 507
    FrontaliersEuropeDuNord[0] = GrandeBretagne;
    FrontaliersEuropeDuNord[1] = Scandinavie;
    FrontaliersEuropeDuNord[2] = EuropeDuSud;
    FrontaliersEuropeDuNord[3] = Ukraine;
    FrontaliersEuropeDuNord[4] = EuropeOccidentale;
    EuropeDuNord.setPaysFrontaliers(FrontaliersEuropeDuNord);

    std::vector<state::Pays> FrontaliersScandinavie(4); //504 : 501, 502, 503, 506
    FrontaliersScandinavie[0] = GrandeBretagne;
    FrontaliersScandinavie[1] = Islande;
    FrontaliersScandinavie[2] = EuropeDuNord;
    FrontaliersScandinavie[3] = Ukraine;
    Scandinavie.setPaysFrontaliers(FrontaliersScandinavie);

    std::vector<state::Pays> FrontaliersEuropeDuSud(5); //505 : 103, 207, 503, 506, 507
    FrontaliersEuropeDuSud[0] = Egypte;
    FrontaliersEuropeDuSud[1] = MoyenOrient;
    FrontaliersEuropeDuSud[2] = EuropeDuNord;
    FrontaliersEuropeDuSud[3] = Ukraine;
    FrontaliersEuropeDuSud[4] = EuropeOccidentale;
    EuropeDuSud.setPaysFrontaliers(FrontaliersEuropeDuSud);

    std::vector<state::Pays> FrontaliersUkraine(6); //506 : 201, 207, 211, 503, 504, 505
    FrontaliersUkraine[0] = Afghanistan;
    FrontaliersUkraine[1] = MoyenOrient;
    FrontaliersUkraine[2] = Oural;
    FrontaliersUkraine[3] = EuropeDuNord;
    FrontaliersUkraine[4] = Scandinavie;
    FrontaliersUkraine[5] = EuropeDuSud;
    Ukraine.setPaysFrontaliers(FrontaliersUkraine);

    std::vector<state::Pays> FrontaliersEuropeOccidentale(4); //507 : 105, 501, 503, 504
    FrontaliersEuropeOccidentale[0] = AfriqueDuNord;
    FrontaliersEuropeOccidentale[1] = GrandeBretagne;
    FrontaliersEuropeOccidentale[2] = EuropeDuNord;
    FrontaliersEuropeOccidentale[3] = Scandinavie;
    EuropeOccidentale.setPaysFrontaliers(FrontaliersEuropeOccidentale);

    std::vector<state::Pays> FrontaliersAustralieOrientale(2); //601 : 603, 604
    FrontaliersAustralieOrientale[0] = NouvelleGuinee;
    FrontaliersAustralieOrientale[1] = AustralieOccidentale;
    AustralieOrientale.setPaysFrontaliers(FrontaliersAustralieOrientale);

    std::vector<state::Pays> FrontaliersIndonesie(3); //602 : 209, 603, 604
    FrontaliersIndonesie[0] = Siam;
    FrontaliersIndonesie[1] = NouvelleGuinee;
    FrontaliersIndonesie[2] = AustralieOccidentale;
    Indonesie.setPaysFrontaliers(FrontaliersIndonesie);

    std::vector<state::Pays> FrontaliersNouvelleGuinee(3); //603 : 601, 602, 604
    FrontaliersNouvelleGuinee[0] = AustralieOrientale;
    FrontaliersNouvelleGuinee[1] = Indonesie;
    FrontaliersNouvelleGuinee[2] = AustralieOccidentale;
    NouvelleGuinee.setPaysFrontaliers(FrontaliersNouvelleGuinee);

    std::vector<state::Pays> FrontaliersAustralieOccidentale(3); //604 : 601, 602, 603
    FrontaliersAustralieOccidentale[0] = AustralieOrientale;
    FrontaliersAustralieOccidentale[1] = Indonesie;
    FrontaliersAustralieOccidentale[2] = NouvelleGuinee;
    AustralieOccidentale.setPaysFrontaliers(FrontaliersAustralieOccidentale);

    std::map<std::string, state::Pays> mapPays;
    mapPays["Congo"] = Congo;
    mapPays["Afrique De L'Est"] = AfriqueDeLEst;
    mapPays["Egypte"] = Egypte;
    mapPays["Madagascar"] = Madagascar;
    mapPays["Afrique Du Nord"] = AfriqueDuNord;
    mapPays["Afrique Du Sud"] = AfriqueDuSud;
    mapPays["Afghanistan"] = Afghanistan;
    mapPays["Chine"] = Chine;
    mapPays["Inde"] = Inde;
    mapPays["Tchita"] = Tchita;
    mapPays["Japon"] = Japon;
    mapPays["Kamtchatka"] = Kamtchatka;
    mapPays["Moyen Orient"] = MoyenOrient;
    mapPays["Mongolie"] = Mongolie;
    mapPays["Siam"] = Siam;
    mapPays["Siberie"] = Siberie;
    mapPays["Oural"] = Oural;
    mapPays["Yakoutie"] = Yakoutie;
    mapPays["Alaska"] = Alaska;
    mapPays["Alberta"] = Alberta;
    mapPays["Amerique Centrale"] = AmeriqueCentrale;
    mapPays["Etats De L'Est"] = EtatsDeLEst;
    mapPays["Groenland"] = Groenland;
    mapPays["Territoires Du Nord-Ouest"] = TerritoiresDuNordOuest;
    mapPays["Ontario"] = Ontario;
    mapPays["Quebec"] = Quebec;
    mapPays["Etats De L'Ouest"] = EtatsDeLOuest;
    mapPays["Argentine"] = Argentine;
    mapPays["Brésil"] = Bresil;
    mapPays["Pérou"] = Perou;
    mapPays["Vénézuela"] = Venezuela;
    mapPays["Grande Bretagne"] = GrandeBretagne;
    mapPays["Islande"] = Islande;
    mapPays["Europe Du Nord"] = EuropeDuNord;
    mapPays["Scandinavie"] = Scandinavie;
    mapPays["Europe Du Sud"] = EuropeDuSud;
    mapPays["Ukraine"] = Ukraine;
    mapPays["Europe Occidentale"] = EuropeOccidentale;
    mapPays["Australie Orientale"] = AustralieOrientale;
    mapPays["Indonesie"] = Indonesie;
    mapPays["Nouvelle Guinée"] = NouvelleGuinee;
    mapPays["Australie Occidentale"] = AustralieOccidentale;

    return mapPays;
}*/


}
