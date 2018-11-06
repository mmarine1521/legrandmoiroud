#include "ElementTab.h"
#include "Element.h"
#include "state.h"
#include <stdio.h>

namespace state {

ElementTab::ElementTab (std::vector<std::unique_ptr<Element>> elementList) : elementList(elementList){
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

std::vector<std::unique_ptr<Element>> ElementTab::getElementList () const{
	return elementList ;
}

void ElementTab::addElement (std::unique_ptr<Element> element){
	elementList.push_back(element);
}

Position ElementTab::getElementPosition (std::unique_ptr<Element> element) const{
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i]==element){
      Element* e = elementList[i].get();
			return e->getPosition();
		}
	}
}

void ElementTab::setElementPosition (Position position, std::unique_ptr<Element> element){
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i]==element){
			elementList[i].setPosition(position);
		}
	}
}

std::unique_ptr<Element> element ElementTab::getLocatedElement (Position position) const{
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i].getPosition() == position){
			return elementList[i] ;
		}
	}
}

}
