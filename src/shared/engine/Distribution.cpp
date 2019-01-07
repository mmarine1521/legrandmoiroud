#include "Distribution.h"

namespace engine {

Distribution::Distribution() 
{
}
Distribution::~Distribution (){
}

IdCommande const Distribution::getIdCommande (){
	return DISTRIBUTION_c;
}

void Distribution::exec (state::State& state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	std::vector<int> listeEntiers;
	for (int i=0; i<42; i++){
	  listeEntiers.push_back(i);
	}

	srand (time(NULL));
	int nbAleatoire;
	std::vector<int> listeMelangee;
	for (int i = 42; i > 0; i--){
	  nbAleatoire = rand() % i;
	  listeMelangee.push_back(listeEntiers[nbAleatoire]);
	  listeEntiers.erase(listeEntiers.begin() + nbAleatoire);
	}

	std::cout << "Le joueur 1 possède :" << std::endl;
	for(size_t i=0; i<14; i++){
	  ptr_armee = listeArmee[listeMelangee[i]].get();
	  ptr_armee->setIdJoueur(1);
		ptr_armee->setNombre(1);
		std::cout << ptr_armee->getPays() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Le joueur 2 possède :" << std::endl;
	for(size_t i=14; i<28; i++){
	  ptr_armee = listeArmee[listeMelangee[i]].get();
	  ptr_armee->setIdJoueur(2);
		ptr_armee->setNombre(1);
		std::cout << ptr_armee->getPays() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Le joueur 3 possède :" << std::endl;
	for(size_t i=28; i<42; i++){
	  ptr_armee = listeArmee[listeMelangee[i]].get();
	  ptr_armee->setIdJoueur(3);
		ptr_armee->setNombre(1);
		std::cout << ptr_armee->getPays() << std::endl;
	}
	std::cout << std::endl;
}

void Distribution::undo (state::State& state){
	state::ElementTab& tabArmee = state.getArmeeTab();
	std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
	state::Element* ptr_armee = 0;

	for(size_t i=0; i<listeArmee.size(); i++){
		ptr_armee = listeArmee[i].get();
		ptr_armee->setIdJoueur(0);
	}
}

}
