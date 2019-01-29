// Generated by dia2code
#ifndef STATE__STATE__H
#define STATE__STATE__H

#include <string>
#include <vector>

namespace state {
  class ElementTab;
}

#include "ElementTab.h"
#include "CarteForce.h"
#include "StepId.h"

namespace state {

  /// class State - 
  class State {
    // Associations
    state::StepId stepId;
    // Attributes
  private:
    ElementTab armeeTab;
    ElementTab cartePiocheTab;
    ElementTab carteEnjeuTab;
    ElementTab carteDefausseTab;
    ElementTab paysTab;
    ElementTab continentTab;
    int tourId;
    int idJoueur;
    std::string paysAttaquant;
    std::string paysAttaque;
    int nbDesAttaquant;
    int nbDesAttaque;
    std::vector<int> desRouges;
    std::vector<int> desBleus;
    int victoire;
    int nbCartes;
    std::vector<int> armeesRepartition;
    std::vector<std::string> blackList;
    std::vector<CarteForce> typeCartes;
    // Operations
  public:
    State ();
    virtual ~State ();
    ElementTab& getArmeeTab ();
    ElementTab& getCartePiocheTab ();
    ElementTab& getCarteEnjeuTab ();
    ElementTab& getCarteDefausseTab ();
    ElementTab& getPaysTab ();
    ElementTab& getContinentTab ();
    int getTourId ();
    int getIdJoueur ();
    StepId getStepId ();
    std::string getPaysAttaquant ();
    std::string getPaysAttaque ();
    int getNbDesAttaquant ();
    int getNbDesAttaque ();
    std::vector<int> getDesRouges ();
    std::vector<int> getDesBleus ();
    int getVictoire ();
    int getNbCartes ();
    int getArmeesRepartition (int idJoueur);
    std::vector<std::string> getBlackList ();
    std::vector<CarteForce> getTypeCartes ();
    int getNbPays (int idJoueur);
    void setArmeeTab (ElementTab armee);
    void setCartePiocheTab (ElementTab cartePioche);
    void setCarteEnjeuTab (ElementTab carteEnjeu);
    void setCarteDefausseTab (ElementTab carteDefausse);
    void setPaysTab (ElementTab pays);
    void setContinentTab (ElementTab continent);
    void setTourId (int tourId);
    void setIdJoueur (int idJoueur);
    void setStepId (StepId stepId);
    void setPaysAttaquant (std::string paysAttaquant);
    void setPaysAttaque (std::string paysAttaque);
    void setNbDesAttaquant (int nbDesAttaquant);
    void setNbDesAttaque (int nbDesAttaque);
    /// 	
    /// @param desRouges		(???) 
    void setDesRouges (std::vector<int> desRouges);
    void setDesBleus (std::vector<int> desBleus);
    void setVictoire (int victoire);
    void setNbCartes (int nbCartes);
    void initializeArmeesRepartition ();
    void setArmeesRepartition (int idJoueur, int armeesRepartition);
    void setBlackList (std::string pays);
    void clearBlackList ();
    void setTypeCarte (CarteForce type);
    void clearTypeCarte ();
    void deleteTypeCarte ();
    // Setters and Getters
  };

};

#endif
