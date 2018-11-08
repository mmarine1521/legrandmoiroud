#include "Engine.h"

namespace engine {

Engine::Engine (){
}

Engine::~Engine (){
}

state::State Engine::getCurrentState (){
  return this->currentState;
}

void Engine::setArretJeu(bool arretJeu){
  this->arretJeu = arretJeu;
}

}
