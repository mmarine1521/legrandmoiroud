// Generated by dia2code
#ifndef RENDER__STATETILESET__H
#define RENDER__STATETILESET__H

#include <vector>
#include <string>

namespace render {
  class Tile;
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"

namespace render {

  /// class StateTileSet - 
  class StateTileSet : public render::TileSet {
    // Attributes
  private:
    std::vector<Tile> pays;
    // Operations
  public:
    StateTileSet ();
    int const getCellWidth ();
    int const getCellHeight ();
    const std::string getImageFile () const;
    // Setters and Getters
  };

};

#endif
