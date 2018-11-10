#include "ElementTab.h"

namespace state {

ElementTab::ElementTab (){
}

ElementTab::~ElementTab(){
}

int ElementTab::getWidth (){
  return this->width;
}

std::vector<std::shared_ptr<Element>> ElementTab::getElementList () const{
  return elementList;
}

void ElementTab::addElement (std::shared_ptr<Element> element){
	elementList.push_back(element->clone());
}

Position ElementTab::getElementPosition (std::shared_ptr<Element> element) const{
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i]==element){
      Element* e = elementList[i].get();
			return e->getPosition();
		}
	}
  Position pos(-1, -1);
  return pos;
}

void ElementTab::setElementPosition (Position position, std::shared_ptr<Element> element){
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i]==element){
      Element* e = elementList[i].get();
			return e->setPosition(position);
		}
	}
}

Element* ElementTab::getLocatedElement (Position position) const{
  Element* e = 0;
	for(size_t i=0; i<elementList.size(); i++){
    e = elementList[i].get();
		if(e->getPosition() == position){
			return e;
		}
	}
  e = 0;
  return e;
}

/*
void ElementTab::melange (){
  srand (time(NULL));
  int longueur = elementList.size();
  int e;
  std::vector<std::shared_ptr<Element>> listeMelangee;
  for (int i = longueur; i > 0; i--){
    e = rand() % i;
    listeMelangee.push_back(elementList[e]);
    elementList.erase(e);
  }
  elementList = listeMelangee;
}
*/


void ElementTab::setArmeeTab (){
  //AFRIQUE
  Armee* armeeCongo = new Armee("Congo");
  elementList.push_back(armeeCongo->clone());
  Armee* armeeAfriqueDeLEst = new Armee("Afrique De L'Est");
  elementList.push_back(armeeAfriqueDeLEst->clone());
  Armee* armeeEgypte = new Armee("Egypte");
  elementList.push_back(armeeEgypte->clone());
  Armee* armeeMadagascar = new Armee("Madagascar");
  elementList.push_back(armeeMadagascar->clone());
  Armee* armeeAfriqueDuNord = new Armee("Afrique Du Nord");
  elementList.push_back(armeeAfriqueDuNord->clone());
  Armee* armeeAfriqueDuSud = new Armee("Afrique Du Sud");
  elementList.push_back(armeeAfriqueDuSud->clone());

  //ASIE
  Armee* armeeAfghanistan = new Armee("Afghanistan");
  elementList.push_back(armeeAfghanistan->clone());
  Armee* armeeChine = new Armee("Chine");
  elementList.push_back(armeeChine->clone());
  Armee* armeeInde = new Armee("Inde");
  elementList.push_back(armeeInde->clone());
  Armee* armeeTchita = new Armee("Tchita");
  elementList.push_back(armeeTchita->clone());
  Armee* armeeJapon = new Armee("Japon");
  elementList.push_back(armeeJapon->clone());
  Armee* armeeKamtchatka = new Armee("Kamtchatka");
  elementList.push_back(armeeKamtchatka->clone());
  Armee* armeeMoyenOrient = new Armee("Moyen-Orient");
  elementList.push_back(armeeMoyenOrient->clone());
  Armee* armeeMongolie = new Armee("Mongolie");
  elementList.push_back(armeeMongolie->clone());
  Armee* armeeSiam = new Armee("Siam");
  elementList.push_back(armeeSiam->clone());
  Armee* armeeSiberie = new Armee("Sibérie");
  elementList.push_back(armeeSiberie->clone());
  Armee* armeeOural = new Armee("Oural");
  elementList.push_back(armeeOural->clone());
  Armee* armeeYakoutie = new Armee("Yakoutie");
  elementList.push_back(armeeYakoutie->clone());

  //AMERIQUE DU NORD
  Armee* armeeAlaska = new Armee("Alaska");
  elementList.push_back(armeeAlaska->clone());
  Armee* armeeAlberta = new Armee("Alberta");
  elementList.push_back(armeeAlberta->clone());
  Armee* armeeAmeriqueCentrale = new Armee("Amérique Centrale");
  elementList.push_back(armeeAmeriqueCentrale->clone());
  Armee* armeeEtatsDeLEst = new Armee("Etats De L'Est");
  elementList.push_back(armeeEtatsDeLEst->clone());
  Armee* armeeGroenland = new Armee("Groenland");
  elementList.push_back(armeeGroenland->clone());
  Armee* armeeTerritoiresDuNordOuest = new Armee("Territoires Du Nord-Ouest");
  elementList.push_back(armeeTerritoiresDuNordOuest->clone());
  Armee* armeeOntario = new Armee("Ontario");
  elementList.push_back(armeeOntario->clone());
  Armee* armeeQuebec = new Armee("Québec");
  elementList.push_back(armeeQuebec->clone());
  Armee* armeeEtatsDeLOuest = new Armee("Etats De L'Ouest");
  elementList.push_back(armeeEtatsDeLOuest->clone());

  //AMERIQUE DU SUD
  Armee* armeeArgentine = new Armee("Argentine");
  elementList.push_back(armeeArgentine->clone());
  Armee* armeeBresil = new Armee("Brésil");
  elementList.push_back(armeeBresil->clone());
  Armee* armeePerou = new Armee("Pérou");
  elementList.push_back(armeePerou->clone());
  Armee* armeeVenezuela = new Armee("Venezuela");
  elementList.push_back(armeeVenezuela->clone());

  //EUROPE
  Armee* armeeGrandeBretagne = new Armee("Grande-Bretagne");
  elementList.push_back(armeeGrandeBretagne->clone());
  Armee* armeeIslande = new Armee("Islande");
  elementList.push_back(armeeIslande->clone());
  Armee* armeeEuropeDuNord = new Armee("Europe Du Nord");
  elementList.push_back(armeeEuropeDuNord->clone());
  Armee* armeeScandinavie = new Armee("Scandinavie");
  elementList.push_back(armeeScandinavie->clone());
  Armee* armeeEuropeDuSud = new Armee("Europe Du Sud");
  elementList.push_back(armeeEuropeDuSud->clone());
  Armee* armeeUkraine = new Armee("Ukraine");
  elementList.push_back(armeeUkraine->clone());
  Armee* armeeEuropeOccidentale = new Armee("Europe Occidentale");
  elementList.push_back(armeeEuropeOccidentale->clone());

  //OCEANIE
  Armee* armeeAustralieOrientale = new Armee("Australie Orientale");
  elementList.push_back(armeeAustralieOrientale->clone());
  Armee* armeeIndonesie = new Armee("Indonésie");
  elementList.push_back(armeeIndonesie->clone());
  Armee* armeeNouvelleGuinee = new Armee("Nouvelle-Guinée");
  elementList.push_back(armeeNouvelleGuinee->clone());
  Armee* armeeAustralieOccidentale = new Armee("Australie Occidentale");
  elementList.push_back(armeeAustralieOccidentale->clone());
}

void ElementTab::setCartePiocheTab (){
  Carte* carte1 = new Carte(1,CANON);
  elementList.push_back(carte1->clone());
  Carte* carte2 = new Carte(2,CANON);
  elementList.push_back(carte2->clone());
  Carte* carte3 = new Carte(3,CANON);
  elementList.push_back(carte3->clone());
  Carte* carte4 = new Carte(4,CANON);
  elementList.push_back(carte4->clone());
  Carte* carte5 = new Carte(5,CANON);
  elementList.push_back(carte5->clone());
  Carte* carte6 = new Carte(6,CANON);
  elementList.push_back(carte6->clone());
  Carte* carte7 = new Carte(7,CANON);
  elementList.push_back(carte7->clone());
  Carte* carte8 = new Carte(8,CANON);
  elementList.push_back(carte8->clone());
  Carte* carte9 = new Carte(9,CANON);
  elementList.push_back(carte9->clone());
  Carte* carte10 = new Carte(10,CANON);
  elementList.push_back(carte10->clone());
  Carte* carte11 = new Carte(11,CANON);
  elementList.push_back(carte11->clone());
  Carte* carte12 = new Carte(12,CANON);
  elementList.push_back(carte12->clone());
  Carte* carte13 = new Carte(13,CANON);
  elementList.push_back(carte13->clone());
  Carte* carte14 = new Carte(14,CANON);
  elementList.push_back(carte14->clone());

  Carte* carte15 = new Carte(15,SOLDAT);
  elementList.push_back(carte15->clone());
  Carte* carte16 = new Carte(16,SOLDAT);
  elementList.push_back(carte16->clone());
  Carte* carte17 = new Carte(17,SOLDAT);
  elementList.push_back(carte17->clone());
  Carte* carte18 = new Carte(18,SOLDAT);
  elementList.push_back(carte18->clone());
  Carte* carte19 = new Carte(19,SOLDAT);
  elementList.push_back(carte19->clone());
  Carte* carte20 = new Carte(20,SOLDAT);
  elementList.push_back(carte20->clone());
  Carte* carte21 = new Carte(21,SOLDAT);
  elementList.push_back(carte21->clone());
  Carte* carte22 = new Carte(22,SOLDAT);
  elementList.push_back(carte22->clone());
  Carte* carte23 = new Carte(23,SOLDAT);
  elementList.push_back(carte23->clone());
  Carte* carte24 = new Carte(24,SOLDAT);
  elementList.push_back(carte24->clone());
  Carte* carte25 = new Carte(25,SOLDAT);
  elementList.push_back(carte25->clone());
  Carte* carte26 = new Carte(26,SOLDAT);
  elementList.push_back(carte26->clone());
  Carte* carte27 = new Carte(27,SOLDAT);
  elementList.push_back(carte27->clone());
  Carte* carte28 = new Carte(28,SOLDAT);
  elementList.push_back(carte28->clone());

  Carte* carte29 = new Carte(29,TANK);
  elementList.push_back(carte29->clone());
  Carte* carte30 = new Carte(30,TANK);
  elementList.push_back(carte30->clone());
  Carte* carte31 = new Carte(31,TANK);
  elementList.push_back(carte31->clone());
  Carte* carte32 = new Carte(32,TANK);
  elementList.push_back(carte32->clone());
  Carte* carte33 = new Carte(33,TANK);
  elementList.push_back(carte33->clone());
  Carte* carte34 = new Carte(34,TANK);
  elementList.push_back(carte34->clone());
  Carte* carte35 = new Carte(35,TANK);
  elementList.push_back(carte35->clone());
  Carte* carte36 = new Carte(36,TANK);
  elementList.push_back(carte36->clone());
  Carte* carte37 = new Carte(37,TANK);
  elementList.push_back(carte37->clone());
  Carte* carte38 = new Carte(38,TANK);
  elementList.push_back(carte38->clone());
  Carte* carte39 = new Carte(39,TANK);
  elementList.push_back(carte39->clone());
  Carte* carte40 = new Carte(40,TANK);
  elementList.push_back(carte40->clone());
  Carte* carte41 = new Carte(41,TANK);
  elementList.push_back(carte41->clone());
  Carte* carte42 = new Carte(42,TANK);
  elementList.push_back(carte42->clone());
}

void ElementTab::setPaysTab (){
  std::vector<std::string> FrontaliersCongo(3); //101 : 102, 105, 106
  FrontaliersCongo[0] = "Afrique De L'Est";
  FrontaliersCongo[1] = "Afrique Du Nord";
  FrontaliersCongo[2] = "Afrique Du Sud";

  std::vector<std::string> FrontaliersAfriqueDeLEst(6); //102 : 101, 103, 104, 105, 106, 207
  FrontaliersAfriqueDeLEst[0] = "Congo";
  FrontaliersAfriqueDeLEst[1] = "Egypte";
  FrontaliersAfriqueDeLEst[2] = "Madagascar";
  FrontaliersAfriqueDeLEst[3] = "Afrique Du Nord";
  FrontaliersAfriqueDeLEst[4] = "Afrique Du Sud";
  FrontaliersAfriqueDeLEst[5] = "MoyenOrient";

  std::vector<std::string> FrontaliersEgypte(4); //103 : 102, 105, 207, 505
  FrontaliersEgypte[0] = "Afrique De L'Est";
  FrontaliersEgypte[1] = "Afrique Du Nord";
  FrontaliersEgypte[2] = "Moyen-Orient";
  FrontaliersEgypte[3] = "Europe Du Sud";

  std::vector<std::string> FrontaliersMadagascar(2); //104 : 102, 106
  FrontaliersMadagascar[0] = "Afrique De L'Est";
  FrontaliersMadagascar[1] = "Afrique Du Sud";

  std::vector<std::string> FrontaliersAfriqueDuNord(5); //105 : 101, 102, 103, 402, 507
  FrontaliersAfriqueDuNord[0] = "Congo";
  FrontaliersAfriqueDuNord[1] = "Afrique De L'Est";
  FrontaliersAfriqueDuNord[2] = "Egypte";
  FrontaliersAfriqueDuNord[3] = "Brésil";
  FrontaliersAfriqueDuNord[4] = "Europe Occidentale";

  std::vector<std::string> FrontaliersAfriqueDuSud(3); //106 : 101, 102, 104
  FrontaliersAfriqueDuSud[0] = "Congo";
  FrontaliersAfriqueDuSud[1] = "Afrique De L'Est";
  FrontaliersAfriqueDuSud[2] = "Madagascar";

  std::vector<std::string> FrontaliersAfghanistan(5); //201 : 202, 203, 207, 211, 506
  FrontaliersAfghanistan[0] = "Chine";
  FrontaliersAfghanistan[1] = "Inde";
  FrontaliersAfghanistan[2] = "Moyen-Orient";
  FrontaliersAfghanistan[3] = "Oural";
  FrontaliersAfghanistan[4] = "Ukraine";

  std::vector<std::string> FrontaliersChine(6); //202 : 201, 203, 208, 209, 210, 211
  FrontaliersChine[0] = "Afghanistan";
  FrontaliersChine[1] = "Inde";
  FrontaliersChine[2] = "Mongolie";
  FrontaliersChine[3] = "Siam";
  FrontaliersChine[4] = "Sibérie";
  FrontaliersChine[5] = "Oural";

  std::vector<std::string> FrontaliersInde(4); //203 : 201, 202, 207, 209
  FrontaliersInde[0] = "Afghanistan";
  FrontaliersInde[1] = "Chine";
  FrontaliersInde[2] = "Moyen-Orient";
  FrontaliersInde[3] = "Siam";

  std::vector<std::string> FrontaliersTchita(4); //204 : 206, 208, 210, 212
  FrontaliersTchita[0] = "Kamtchatka";
  FrontaliersTchita[1] = "Mongolie";
  FrontaliersTchita[2] = "Sibérie";
  FrontaliersTchita[3] = "Yakoutie";

  std::vector<std::string> FrontaliersJapon(2); //205 : 206, 208
  FrontaliersTchita[0] = "Kamtchatka";
  FrontaliersTchita[1] = "Mongolie";

  std::vector<std::string> FrontaliersKamtchatka(5); //206 : 204, 205, 208, 212, 301
  FrontaliersKamtchatka[0] = "Tchita";
  FrontaliersKamtchatka[1] = "Japon";
  FrontaliersKamtchatka[2] = "Mongolie";
  FrontaliersKamtchatka[3] = "Yakoutie";
  FrontaliersKamtchatka[4] = "Alaska";

  std::vector<std::string> FrontaliersMoyenOrient(6); //207 : 102, 103, 201, 203, 505, 506
  FrontaliersMoyenOrient[0] = "Afrique De L'Est";
  FrontaliersMoyenOrient[1] = "Egypte";
  FrontaliersMoyenOrient[2] = "Afghanistan";
  FrontaliersMoyenOrient[3] = "Inde";
  FrontaliersMoyenOrient[4] = "Europe Du Sud";
  FrontaliersMoyenOrient[5] = "Ukraine";

  std::vector<std::string> FrontaliersMongolie(5); //208 : 202, 204, 205, 206, 210
  FrontaliersMongolie[0] = "Chine";
  FrontaliersMongolie[1] = "Tchita";
  FrontaliersMongolie[2] = "Japon";
  FrontaliersMongolie[3] = "Kamtchatka";
  FrontaliersMongolie[4] = "Sibérie";

  std::vector<std::string> FrontaliersSiam(3); //209 : 202, 203, 602
  FrontaliersSiam[0] = "Chine";
  FrontaliersSiam[1] = "Inde";
  FrontaliersSiam[2] = "Indonésie";

  std::vector<std::string> FrontaliersSiberie(5); //210 : 202, 204, 208, 211, 212
  FrontaliersSiberie[0] = "Chine";
  FrontaliersSiberie[1] = "Tchita";
  FrontaliersSiberie[2] = "Mongolie";
  FrontaliersSiberie[3] = "Oural";
  FrontaliersSiberie[4] = "Yakoutie";

  std::vector<std::string> FrontaliersOural(4); //211 : 201, 202, 210, 506
  FrontaliersOural[0] = "Afghanistan";
  FrontaliersOural[1] = "Chine";
  FrontaliersOural[2] = "Sibérie";
  FrontaliersOural[3] = "Ukraine";

  std::vector<std::string> FrontaliersYakoutie(3); //212 : 204, 206, 210
  FrontaliersYakoutie[0] = "Tchita";
  FrontaliersYakoutie[1] = "Kamtchatka";
  FrontaliersYakoutie[2] = "Sibérie";

  std::vector<std::string> FrontaliersAlaska(3); //301 : 206, 302, 306
  FrontaliersAlaska[0] = "Kamtchatka";
  FrontaliersAlaska[1] = "Alberta";
  FrontaliersAlaska[2] = "Territoires Du Nord-Ouest";

  std::vector<std::string> FrontaliersAlberta(4); //302 : 301, 306, 307, 309
  FrontaliersAlberta[0] = "Alaska";
  FrontaliersAlberta[1] = "Territoires Du Nord-Ouest";
  FrontaliersAlberta[2] = "Ontario";
  FrontaliersAlberta[3] = "Etats De L'Ouest";

  std::vector<std::string> FrontaliersAmeriqueCentrale(3); //303 : 304, 309, 404
  FrontaliersAmeriqueCentrale[0] = "Etats De L'Est";
  FrontaliersAmeriqueCentrale[1] = "Etats De L'Ouest";
  FrontaliersAmeriqueCentrale[2] = "Venezuela";

  std::vector<std::string> FrontaliersEtatsDeLEst(4); //304 : 303, 307, 308, 309
  FrontaliersEtatsDeLEst[0] = "Amérique Centrale";
  FrontaliersEtatsDeLEst[1] = "Ontario";
  FrontaliersEtatsDeLEst[2] = "Québec";
  FrontaliersEtatsDeLEst[3] = "Etats De L'Ouest";

  std::vector<std::string> FrontaliersGroenland(4); //305 : 306, 307, 308, 502
  FrontaliersGroenland[0] = "Territoires Du Nord-Ouest";
  FrontaliersGroenland[1] = "Ontario";
  FrontaliersGroenland[2] = "Québec";
  FrontaliersGroenland[3] = "Islande";

  std::vector<std::string> FrontaliersTerritoiresDuNordOuest(4); //306 : 301, 302, 305, 307
  FrontaliersTerritoiresDuNordOuest[0] = "Alaska";
  FrontaliersTerritoiresDuNordOuest[1] = "Alberta";
  FrontaliersTerritoiresDuNordOuest[2] = "Groenland";
  FrontaliersTerritoiresDuNordOuest[3] = "Ontario";

  std::vector<std::string> FrontaliersOntario(6); //307 : 302, 304, 305, 306, 308, 309
  FrontaliersOntario[0] = "Alberta";
  FrontaliersOntario[1] = "Etats De L'Est";
  FrontaliersOntario[2] = "Groenland";
  FrontaliersOntario[3] = "Territoires Du Nord-Ouest";
  FrontaliersOntario[4] = "Québec";
  FrontaliersOntario[5] = "Etats De L'Ouest";

  std::vector<std::string> FrontaliersQuebec(3); //308 : 304, 305, 307
  FrontaliersQuebec[0] = "Etats De L'Est";
  FrontaliersQuebec[1] = "Groenland";
  FrontaliersQuebec[2] = "Ontario";

  std::vector<std::string> FrontaliersEtatsDeLOuest(4); //309 : 302, 303, 304, 307
  FrontaliersEtatsDeLOuest[0] = "Alberta";
  FrontaliersEtatsDeLOuest[1] = "Amérique Centrale";
  FrontaliersEtatsDeLOuest[2] = "Etats De L'Est";
  FrontaliersEtatsDeLOuest[3] = "Ontario";

  std::vector<std::string> FrontaliersArgentine(2); //401 : 402, 403
  FrontaliersArgentine[0] = "Brésil";
  FrontaliersArgentine[1] = "Pérou";

  std::vector<std::string> FrontaliersBresil(4); //402 : 105, 401, 403, 404
  FrontaliersBresil[0] = "Afrique Du Nord";
  FrontaliersBresil[1] = "Argentine";
  FrontaliersBresil[2] = "Pérou";
  FrontaliersBresil[3] = "Venezuela";

  std::vector<std::string> FrontaliersPerou(3); //403 : 401, 402, 404
  FrontaliersPerou[0] = "Argentine";
  FrontaliersPerou[1] = "Brésil";
  FrontaliersPerou[2] = "Venezuela";

  std::vector<std::string> FrontaliersVenezuela(3); //404 : 303, 402, 403
  FrontaliersVenezuela[0] = "Amérique Centrale";
  FrontaliersVenezuela[1] = "Brésil";
  FrontaliersVenezuela[2] = "Pérou";

  std::vector<std::string> FrontaliersGrandeBretagne(4); //501 : 502, 503, 504, 507
  FrontaliersGrandeBretagne[0] = "Islande";
  FrontaliersGrandeBretagne[1] = "Europe Du Nord";
  FrontaliersGrandeBretagne[2] = "Scandinavie";
  FrontaliersGrandeBretagne[3] = "Europe Occidentale";

  std::vector<std::string> FrontaliersIslande(3); //502 : 305, 501, 504
  FrontaliersIslande[0] = "Groenland";
  FrontaliersIslande[1] = "Grande-Bretagne";
  FrontaliersIslande[2] = "Scandinavie";

  std::vector<std::string> FrontaliersEuropeDuNord(5); //503 : 501, 504, 505, 506, 507
  FrontaliersEuropeDuNord[0] = "Grande-Bretagne";
  FrontaliersEuropeDuNord[1] = "Scandinavie";
  FrontaliersEuropeDuNord[2] = "Europe Du Sud";
  FrontaliersEuropeDuNord[3] = "Ukraine";
  FrontaliersEuropeDuNord[4] = "Europe Occidentale";

  std::vector<std::string> FrontaliersScandinavie(4); //504 : 501, 502, 503, 506
  FrontaliersScandinavie[0] = "Grande-Bretagne";
  FrontaliersScandinavie[1] = "Islande";
  FrontaliersScandinavie[2] = "Europe Du Nord";
  FrontaliersScandinavie[3] = "Ukraine";

  std::vector<std::string> FrontaliersEuropeDuSud(5); //505 : 103, 207, 503, 506, 507
  FrontaliersEuropeDuSud[0] = "Egypte";
  FrontaliersEuropeDuSud[1] = "Moyen-Orient";
  FrontaliersEuropeDuSud[2] = "Europe Du Nord";
  FrontaliersEuropeDuSud[3] = "Ukraine";
  FrontaliersEuropeDuSud[4] = "Europe Occidentale";

  std::vector<std::string> FrontaliersUkraine(6); //506 : 201, 207, 211, 503, 504, 505
  FrontaliersUkraine[0] = "Afghanistan";
  FrontaliersUkraine[1] = "Moyen-Orient";
  FrontaliersUkraine[2] = "Oural";
  FrontaliersUkraine[3] = "Europe Du Nord";
  FrontaliersUkraine[4] = "Scandinavie";
  FrontaliersUkraine[5] = "Europe Du Sud";

  std::vector<std::string> FrontaliersEuropeOccidentale(4); //507 : 105, 501, 503, 504
  FrontaliersEuropeOccidentale[0] = "Afrique Du Nord";
  FrontaliersEuropeOccidentale[1] = "Grande-Bretagne";
  FrontaliersEuropeOccidentale[2] = "Europe Du Nord";
  FrontaliersEuropeOccidentale[3] = "Scandinavie";

  std::vector<std::string> FrontaliersAustralieOrientale(2); //601 : 603, 604
  FrontaliersAustralieOrientale[0] = "Nouvelle-Guinée";
  FrontaliersAustralieOrientale[1] = "Australie Occidentale";

  std::vector<std::string> FrontaliersIndonesie(3); //602 : 209, 603, 604
  FrontaliersIndonesie[0] = "Siam";
  FrontaliersIndonesie[1] = "Nouvelle-Guinée";
  FrontaliersIndonesie[2] = "Australie Occidentale";

  std::vector<std::string> FrontaliersNouvelleGuinee(3); //603 : 601, 602, 604
  FrontaliersNouvelleGuinee[0] = "Australie Orientale";
  FrontaliersNouvelleGuinee[1] = "Indonésie";
  FrontaliersNouvelleGuinee[2] = "Australie Occidentale";

  std::vector<std::string> FrontaliersAustralieOccidentale(3); //604 : 601, 602, 603
  FrontaliersAustralieOccidentale[0] = "Australie Orientale";
  FrontaliersAustralieOccidentale[1] = "Indonésie";
  FrontaliersAustralieOccidentale[2] = "Nouvelle-Guinée";

  //AFRIQUE
  Pays* Congo = new Pays("Congo", 101, AFRIQUE, FrontaliersCongo);
  elementList.push_back(Congo->clone());
  Pays* AfriqueDeLEst = new Pays("Afrique De L'Est", 102, AFRIQUE, FrontaliersAfriqueDeLEst);
  elementList.push_back(AfriqueDeLEst->clone());
  Pays* Egypte = new Pays("Egypte", 103, AFRIQUE, FrontaliersEgypte);
  elementList.push_back(Egypte->clone());
  Pays* Madagascar = new Pays("Madagascar", 104, AFRIQUE, FrontaliersMadagascar);
  elementList.push_back(Madagascar->clone());
  Pays* AfriqueDuNord = new Pays("Afrique Du Nord", 105, AFRIQUE, FrontaliersAfriqueDuNord);
  elementList.push_back(AfriqueDuNord->clone());
  Pays* AfriqueDuSud = new Pays("Afrique Du Sud", 106, AFRIQUE, FrontaliersAfriqueDuSud);
  elementList.push_back(AfriqueDuSud->clone());

  //ASIE
  Pays* Afghanistan = new Pays("Afghanistan", 201, ASIE, FrontaliersAfghanistan);
  elementList.push_back(Afghanistan->clone());
  Pays* Chine = new Pays("Chine", 202, ASIE, FrontaliersChine);
  elementList.push_back(Chine->clone());
  Pays* Inde = new Pays("Inde", 203, ASIE, FrontaliersInde);
  elementList.push_back(Inde->clone());
  Pays* Tchita = new Pays("Tchita", 204, ASIE, FrontaliersTchita);
  elementList.push_back(Tchita->clone());
  Pays* Japon = new Pays("Japon", 205, ASIE, FrontaliersJapon);
  elementList.push_back(Japon->clone());
  Pays* Kamtchatka = new Pays("Kamtchatka", 206, ASIE, FrontaliersKamtchatka);
  elementList.push_back(Kamtchatka->clone());
  Pays* MoyenOrient = new Pays("Moyen-Orient", 207, ASIE, FrontaliersMoyenOrient);
  elementList.push_back(MoyenOrient->clone());
  Pays* Mongolie = new Pays("Mongolie", 208, ASIE, FrontaliersMongolie);
  elementList.push_back(Mongolie->clone());
  Pays* Siam = new Pays("Siam", 209, ASIE, FrontaliersSiam);
  elementList.push_back(Siam->clone());
  Pays* Siberie = new Pays("Sibérie", 210, ASIE, FrontaliersSiberie);
  elementList.push_back(Siberie->clone());
  Pays* Oural = new Pays("Oural", 211, ASIE, FrontaliersOural);
  elementList.push_back(Oural->clone());
  Pays* Yakoutie = new Pays("Yakoutie", 212, ASIE, FrontaliersYakoutie);
  elementList.push_back(Yakoutie->clone());

  //AMERIQUE DU NORD
  Pays* Alaska = new Pays("Alaska", 301, AMERIQUE_NORD, FrontaliersAlaska);
  elementList.push_back(Alaska->clone());
  Pays* Alberta = new Pays("Alberta", 302, AMERIQUE_NORD, FrontaliersAlberta);
  elementList.push_back(Alberta->clone());
  Pays* AmeriqueCentrale = new Pays("Amérique Centrale", 303, AMERIQUE_NORD, FrontaliersAmeriqueCentrale);
  elementList.push_back(AmeriqueCentrale->clone());
  Pays* EtatsDeLEst = new Pays("Etats De L'Est", 304, AMERIQUE_NORD, FrontaliersEtatsDeLEst);
  elementList.push_back(EtatsDeLEst->clone());
  Pays* Groenland = new Pays("Groenland", 305, AMERIQUE_NORD, FrontaliersGroenland);
  elementList.push_back(Groenland->clone());
  Pays* TerritoiresDuNordOuest = new Pays("Territoires Du Nord-Ouest", 306, AMERIQUE_NORD, FrontaliersTerritoiresDuNordOuest);
  elementList.push_back(TerritoiresDuNordOuest->clone());
  Pays* Ontario = new Pays("Ontario", 307, AMERIQUE_NORD, FrontaliersOntario);
  elementList.push_back(Ontario->clone());
  Pays* Quebec = new Pays("Québec", 308, AMERIQUE_NORD, FrontaliersQuebec);
  elementList.push_back(Quebec->clone());
  Pays* EtatsDeLOuest = new Pays("Etats De L'Ouest", 309, AMERIQUE_NORD, FrontaliersEtatsDeLOuest);
  elementList.push_back(EtatsDeLOuest->clone());

  //AMERIQUE DU SUD
  Pays* Argentine = new Pays("Argentine", 401, AMERIQUE_SUD, FrontaliersArgentine);
  elementList.push_back(Argentine->clone());
  Pays* Bresil = new Pays("Brésil", 402, AMERIQUE_SUD, FrontaliersBresil);
  elementList.push_back(Bresil->clone());
  Pays* Perou = new Pays("Pérou", 403, AMERIQUE_SUD, FrontaliersPerou);
  elementList.push_back(Perou->clone());
  Pays* Venezuela = new Pays("Venezuela", 404, AMERIQUE_SUD, FrontaliersVenezuela);
  elementList.push_back(Venezuela->clone());

  //EUROPE
  Pays* GrandeBretagne = new Pays("Grande Bretagne", 501, EUROPE, FrontaliersGrandeBretagne);
  elementList.push_back(GrandeBretagne->clone());
  Pays* Islande = new Pays("Islande", 502, EUROPE, FrontaliersIslande);
  elementList.push_back(Islande->clone());
  Pays* EuropeDuNord = new Pays("Europe Du Nord", 503,EUROPE, FrontaliersEuropeDuNord);
  elementList.push_back(EuropeDuNord->clone());
  Pays* Scandinavie = new Pays("Scandinavie", 504, EUROPE, FrontaliersScandinavie);
  elementList.push_back(Scandinavie->clone());
  Pays* EuropeDuSud = new Pays("Europe Du Sud", 505, EUROPE, FrontaliersEuropeDuSud);
  elementList.push_back(EuropeDuSud->clone());
  Pays* Ukraine = new Pays("Ukraine", 506, EUROPE, FrontaliersUkraine);
  elementList.push_back(Ukraine->clone());
  Pays* EuropeOccidentale = new Pays("Europe Occidentale", 507, EUROPE, FrontaliersEuropeOccidentale);
  elementList.push_back(EuropeOccidentale->clone());

  //OCEANIE
  Pays* AustralieOrientale = new Pays("Australie Orientale", 601, OCEANIE, FrontaliersAustralieOrientale);
  elementList.push_back(AustralieOrientale->clone());
  Pays* Indonesie = new Pays("Indonésie", 602, OCEANIE, FrontaliersIndonesie);
  elementList.push_back(Indonesie->clone());
  Pays* NouvelleGuinee = new Pays("Nouvelle-Guinée", 603, OCEANIE, FrontaliersNouvelleGuinee);
  elementList.push_back(NouvelleGuinee->clone());
  Pays* AustralieOccidentale = new Pays("Australie Occidentale", 604, OCEANIE, FrontaliersAustralieOccidentale);
  elementList.push_back(AustralieOccidentale->clone());
}

void ElementTab::setContinentTab (){
  //AFRIQUE
  std::vector<std::string> PaysAfrique(6) ;
  PaysAfrique[0] = "Congo" ;
  PaysAfrique[1] = "Afrique De L'Est" ;
  PaysAfrique[2] = "Egypte" ;
  PaysAfrique[3] = "Madagascar" ;
  PaysAfrique[4] = "Afrique Du Nord" ;
  PaysAfrique[5] = "Afrique Du Sud" ;
  Continent* Afrique = new Continent("Afrique", AFRIQUE, MARRON, PaysAfrique);
  elementList.push_back(Afrique->clone());

  //ASIE
  std::vector<std::string> PaysAsie(12) ;
  PaysAsie[0] = "Afghanistan" ;
  PaysAsie[1] = "Chine" ;
  PaysAsie[2] = "Inde" ;
  PaysAsie[3] = "Tchita" ;
  PaysAsie[4] = "Japon" ;
  PaysAsie[5] = "Kamtchatka" ;
  PaysAsie[6] = "Moyen-Orient" ;
  PaysAsie[7] = "Mongolie" ;
  PaysAsie[8] = "Siam" ;
  PaysAsie[9] = "Sibérie" ;
  PaysAsie[10] = "Oural" ;
  PaysAsie[11] = "Yakoutie" ;
  Continent* Asie = new Continent("Asie", ASIE, ROUGE, PaysAsie);
  elementList.push_back(Asie->clone());

  //AMERIQUE DU NORD
  std::vector<std::string> PaysAmeriqueDuNord(9) ;
  PaysAmeriqueDuNord[0] = "Alaska" ;
  PaysAmeriqueDuNord[1] = "Alberta" ;
  PaysAmeriqueDuNord[2] = "Amérique Centrale" ;
  PaysAmeriqueDuNord[3] = "Etats De L'Est" ;
  PaysAmeriqueDuNord[4] = "Groenland" ;
  PaysAmeriqueDuNord[5] = "Territoires Du Nord-Ouest" ;
  PaysAmeriqueDuNord[6] = "Ontario" ;
  PaysAmeriqueDuNord[7] = "Québec" ;
  PaysAmeriqueDuNord[8] = "Etats De L'Ouest" ;
  Continent* AmeriqueDuNord = new Continent("Amérique Du Nord", AMERIQUE_NORD, JAUNE, PaysAmeriqueDuNord);
  elementList.push_back(AmeriqueDuNord->clone());

  //AMERIQUE DU SUD
  std::vector<std::string> PaysAmeriqueDuSud(4) ;
  PaysAmeriqueDuSud[0] = "Argentine" ;
  PaysAmeriqueDuSud[1] = "Brésil" ;
  PaysAmeriqueDuSud[2] = "Pérou";
  PaysAmeriqueDuSud[3] = "Venezuela" ;
  Continent* AmeriqueDuSud = new Continent("Amérique Du Sud", AMERIQUE_SUD, NOIR, PaysAmeriqueDuSud);
  elementList.push_back(AmeriqueDuSud->clone());

  //EUROPE
  std::vector<std::string> PaysEurope(7) ;
  PaysEurope[0] = "Grande-Bretagne" ;
  PaysEurope[1] = "Islande" ;
  PaysEurope[2] = "Europe Du Nord" ;
  PaysEurope[3] = "Scandinavie" ;
  PaysEurope[4] = "Europe Du Sud" ;
  PaysEurope[5] = "Ukraine" ;
  PaysEurope[6] = "Europe Occidentale" ;
  Continent* Europe = new Continent("Europe", EUROPE, VERT, PaysEurope);
  elementList.push_back(Europe->clone());

  //OCEANIE
  std::vector<std::string> PaysOceanie(4) ;
  PaysOceanie[0] = "Australie Orientale" ;
  PaysOceanie[1] = "Indonésie" ;
  PaysOceanie[2] = "Nouvelle-Guinée" ;
  PaysOceanie[3] = "Australie Occidentale" ;
  Continent* Oceanie = new Continent("Océanie", OCEANIE, VERT_FONCE, PaysOceanie);
  elementList.push_back(Oceanie->clone());
}

}
