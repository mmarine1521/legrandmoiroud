#include "state.h"

#include <iostream>

using namespace std;
using namespace state;

int main(int argc,char* argv[]){
	srand (time(0)); //initialisation une fois pour toute du srand
	ElementTab tabArmee = ElementTab() ;
	tabArmee.ElementTab::remplirArmeeTab() ;
	ElementTab tabCartePioche = ElementTab();
	tabCartePioche.ElementTab::remplirCartePiocheTab();
	ElementTab tabCarteEnjeu = ElementTab();
	ElementTab tabCarteDefausse = ElementTab();
	ElementTab tabPays = ElementTab();
	tabPays.ElementTab::remplirPaysTab();
	ElementTab tabContinent = ElementTab();
	tabContinent.ElementTab::remplirContinentTab();

	State currentState = state::State() ;
	currentState.setStepId(state::DISTRIBUTION_s);
	currentState.setArmeeTab(tabArmee);
	currentState.setCartePiocheTab(tabCartePioche);
	currentState.setCarteEnjeuTab(tabCarteEnjeu);
	currentState.setCarteDefausseTab(tabCarteDefausse);
	currentState.setPaysTab(tabPays);
	currentState.setContinentTab(tabContinent);
	currentState.setTourId(1);
	currentState.setIdJoueur(1);
	currentState.setNbCartes(3);
	currentState.initializeArmeesRepartition();

	if (argc > 1){ // vérifie s'il y a un argument
		string av(argv[1]);
		if (av == "hello") {   // vérification que l'argument est le bon
	  	cout << "Bonjour le monde !" << endl;
	  }
		else if (av == "state"){
	  	//Test_Unitaire();
	 	}
	}
}
