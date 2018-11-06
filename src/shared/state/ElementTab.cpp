#include "ElementTab.h"
#include "Element.h"
#include "state.h"
#include <stdio.h>

namespace state {

ElementTab::ElementTab (std::vector<Element> elementList){
		this->elementList = elementList ;
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

std::vector<Element> ElementTab::getElementList () const{
	return elementList ;
}

void ElementTab::addElement (Element element){
	elementList.pushback(element);
}

Position ElementTab::getElementPosition (Element element) const{
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i]==element){
			return elementList[i].getPosition();
		}
	}
}

void ElementTab::setElementPosition (Position position, Element element){
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i]==element){
			elementList[i].setPosition(position);
		}
	}
}

Element ElementTab::getLocatedElement (Position position) const{
	for(size_t i=0; i<elementList.size(); i++){
		if(elementList[i].getPosition() == position){
			return elementList[i] ;
		}
	}
}

}
