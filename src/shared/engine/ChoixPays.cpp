#include "ChoixPays.h"

namespace engine {

ChoixPays::ChoixPays (std::string pays) : pays(pays){
}

ChoixPays::~ChoixPays (){
}

std::string ChoixPays::getPays(){
  return this->pays;
}

}
