#include "ElementTab.h"
#include <stdio.h>

namespace state {

//ElementTab::ElementTab (std::vector<std::unique_ptr<Element>> elementList) : elementList(elementList){
ElementTab::ElementTab (){
}

ElementTab::~ElementTab(){
	/*for(size_t i=0; i<elementList.size(); i++)
	{
		delete elementList[i];
		elementList[i]=0 ;
	}*/ // A utiliser pour des pointeurs
}

int ElementTab::getWidth (){
  return this->width;
}

std::vector<Element*> ElementTab::getElementList () const{
  std::vector<Element*> liste;
  for(size_t i=0; i<elementList.size(); i++){
    Element* e = elementList[i].get();
		liste.push_back(e);
	}
	return liste;
}

void ElementTab::addElement (std::unique_ptr<Element> element){
	elementList.push_back(element->clone());
}

Position ElementTab::getElementPosition (std::unique_ptr<Element> element) const{
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i]==element){
      Element* e = elementList[i].get();
			return e->getPosition();
		}
	}
  Position pos(-1, -1);
  return pos;
}

void ElementTab::setElementPosition (Position position, std::unique_ptr<Element> element){
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

/*std::unique_ptr<Element> ElementTab::getLocatedElement (Position position) const{
  Element* e = 0;
	for(size_t i=0; i<elementList.size(); i++){
    e = elementList[i].get();
		if(e->getPosition() == position){
			return elementList[i] ;
		}
	}
}*/

}
