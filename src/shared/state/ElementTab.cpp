#include "ElementTab.h"
#include "Element.h"
#include "state.h"
#include <stdio.h>

namespace state {

ElementTab::ElementTab (int width, int height, std::vector<Element*> elementList){
	if(width>=0 && height>=0)
	{
		this->width = width ;
		this->height = height ;
		this->elementList = elementList ;
	}
	else
	{
		throw "Dimensions de la MAP incorrectes" ;
	}
}

ElementTab::~ElementTab()
{
	for(size_t i=0; i<elementList.size(); i++)
	{
		delete elementList[i];
		elementList[i]=0 ;
	}
}
int ElementTab::getWidth (){
  return this->width;
}

int ElementTab::getHeight (){
  return this->height;
}

void ElementTab::resize (int width, int height){
  this->width = width;
  this->height = height;
}

std::vector<Element*> ElementTab::getElementList () const
{
	return elementList ;
}

void ElementTab::addElement (Element* e)
{
	elementList.pushback(e);
}
Element* ElementTab::getLocatedElement (Position *position) const
{
	for(size_t i=0; i<elementList.size(); i++)
	{
		Position pos_actuelle = elementList[i]->getPosition();
		if(pos_actuelle.getX() == position->getX() && pos_actuelle.getY() == position->getY())
		{
			return elementList[i] ;
		}

	}
}
void ElementTab::setElement (Position position, Element* element_ptr)
{
	for(size_t i=0 ; i<elementList.size(); i++)
	{
		if(elementList[i]==element_ptr)
		{
			elementList[i]->setPosition(position);
		}
	}
}
}
