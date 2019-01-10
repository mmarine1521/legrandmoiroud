#include "State.h"
#include <iostream>

namespace state {

State::State (){
}

State::~State (){
}

ElementTab& State::getArmeeTab (){
  ElementTab &refArmeeTab = armeeTab;
  return refArmeeTab;
}

ElementTab& State::getCartePiocheTab (){
  ElementTab &refCartePiocheTab = cartePiocheTab;
  return refCartePiocheTab;
}

ElementTab& State::getCarteEnjeuTab (){
  ElementTab &refCarteEnjeuTab = carteEnjeuTab;
  return refCarteEnjeuTab;
}

ElementTab& State::getCarteDefausseTab (){
  ElementTab &refCarteDefausseTab = carteDefausseTab;
  return refCarteDefausseTab;
}

ElementTab& State::getPaysTab (){
  ElementTab &refPaysTab = paysTab;
  return refPaysTab;
}

ElementTab& State::getContinentTab (){
  ElementTab &refContinentTab = continentTab;
  return refContinentTab;
}

int State::getTourId (){
  return this->tourId;
}

int State::getIdJoueur (){
  return this->idJoueur;
}

StepId State::getStepId (){
  return this->stepId;
}

std::string State::getPaysAttaquant (){
  return this->paysAttaquant;
}

std::string State::getPaysAttaque (){
  return this->paysAttaque;
}

int State::getNbDesAttaquant (){
  return this->nbDesAttaquant;
}

int State::getNbDesAttaque (){
  return this->nbDesAttaque;
}

std::vector<int> State::getDesRouges (){
  return this->desRouges;
}

std::vector<int> State::getDesBleus (){
  return this->desBleus;
}

int State::getVictoire (){
  return this->victoire;
}

int State::getNbCartes (){
  return this->nbCartes;
}

int State::getArmeesPlacer (){
  return this->armeesPlacer;
}

int State::getArmeesRepartition(int idJoueur){
  return this->armeesRepartition[idJoueur - 1];
}

std::vector<std::string> State::getBlackList (){
  return this->blackList;
}

std::vector<CarteForce> State::getTypesCartes (){
  return this->typeCartes;
}

void State::setArmeeTab (ElementTab armee){
	this->armeeTab = armee ;
}

void State::setCartePiocheTab (ElementTab cartePioche){
	this->cartePiocheTab = cartePioche;
}

void State::setCarteEnjeuTab (ElementTab carteEnjeu){
	this->carteEnjeuTab = carteEnjeu;
}

void State::setCarteDefausseTab (ElementTab carteDefausse){
	this->carteDefausseTab = carteDefausse;
}

void State::setPaysTab (ElementTab pays){
	this->paysTab = pays;
}

void State::setContinentTab (ElementTab continent){
	this->continentTab = continent;
}

void State::setTourId (int tourId){
  this->tourId = tourId;
}

void State::setIdJoueur (int idJoueur){
  this->idJoueur = idJoueur;
}

void State::setStepId (StepId stepId){
  this->stepId = stepId;
}

void State::setPaysAttaquant (std::string paysAttaquant){
  this->paysAttaquant = paysAttaquant;
}

void State::setPaysAttaque (std::string paysAttaque){
  this->paysAttaque = paysAttaque;
}

void State::setNbDesAttaquant (int nbDesAttaquant){
  this->nbDesAttaquant = nbDesAttaquant;
}

void State::setNbDesAttaque (int nbDesAttaque){
  this->nbDesAttaque = nbDesAttaque;
}

void State::setDesRouges (std::vector<int> desRouges){
  this->desRouges = desRouges;
}

void State::setDesBleus (std::vector<int> desBleus){
  this->desBleus = desBleus;
}

void State::setVictoire (int victoire){
  this->victoire = victoire;
}

void State::setNbCartes (int nbCartes){
  this->nbCartes = nbCartes;
}

void State::setArmeesPlacer (int armeesPlacer){
  this->armeesPlacer = armeesPlacer;
}

void State::setArmeesRepartition (int idJoueur, int armeesRepartition){
  this->armeesRepartition[idJoueur - 1] = armeesRepartition;
}

void State::setBlackList (std::string pays){
  this->blackList.push_back(pays);
}

void State::setTypeCarte (CarteForce type){
  this->typeCartes.push_back(type);
}

void State::deleteTypeCarte (){
  this->typeCartes.pop_back();
}

}
