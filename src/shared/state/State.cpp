#include "State.h"

namespace state {

ElementTab& State::getArmeeTab (){
  ElementTab &refArmeeTab = armeeTab;
  return refArmeeTab;
}

ElementTab& State::getCarteTab (){
  ElementTab &refCarteTab = carteTab;
  return refCarteTab;
}

ElementTab& State::getPaysTab (){
  ElementTab &refPaysTab = paysTab;
  return refPaysTab;
}

ElementTab& State::getContinentTab (){
  ElementTab &refContinentTab = continentTab;
  return refContinentTab;
}
/*
void setArmeeTab ();
void setCarteTab ();
void setPaysContinentTab ();*/

}
