#include "ElementTab.h"

namespace state {

ElementTab::ElementTab (int width, int height) : width(width), height(height){
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

}
