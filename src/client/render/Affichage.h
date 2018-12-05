// Generated by dia2code
#ifndef RENDER__AFFICHAGE__H
#define RENDER__AFFICHAGE__H

#include <SFML/Graphics.hpp>
#include <string>

namespace state {
  class State;
};
namespace sf {
  class Transformable;
  class Drawable;
  class Texture;
  class VertexArray;
};
namespace state {
  class ElementTab;
}

#include "state/ElementTab.h"
#include "state/State.h"

namespace render {

  /// class Affichage - 
  class Affichage : public sf::Transformable, public sf::Drawable {
    // Associations
    // Attributes
  public:
    sf::RenderWindow* window;
    // Operations
  public:
    static void AfficheMap (state::State& state, sf::RenderWindow& window);
    static void AfficheCartes (state::State& state, sf::RenderWindow& window);
    static void AfficheArmees (state::State& state, sf::RenderWindow& window);
     static void AfficheNombre (state::State& state, sf::RenderWindow& window);
    static std::string PaysClic (sf::RenderWindow& window, sf::Event event);
    static int NombreClic (sf::RenderWindow& window, sf::Event event);
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    static void AfficheChoixNbrArmees (state::State& state, sf::RenderWindow& window);
    static void AfficheTitre (state::State& state, sf::RenderWindow& window);
    static void AfficheQuestion1 (state::State& state, sf::RenderWindow& window);
    // Setters and Getters
  };

};

#endif
