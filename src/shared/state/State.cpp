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

}
