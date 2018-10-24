// Generated by dia2code
#ifndef RENDER__MOBILETILESET__H
#define RENDER__MOBILETILESET__H

#include <vector>
#include <string>

namespace render {
  class Tile;
};
namespace state {
  class Element;
};
namespace render {
  class TileSet;
}

#include "Tile.h"
#include "TileSet.h"

namespace render {

  /// class MobileTileSet - 
  class MobileTileSet : public render::TileSet {
    // Attributes
  private:
    std::vector<Tile> armee;
    std::vector<Tile> c_tank;
    std::vector<Tile> c_canon;
    std::vector<Tile> c_fantassin;
    // Operations
  public:
    MobileTileSet ();
    ~MobileTileSet ();
    int const getCellWidth ();
    int const getCellHeight ();
    const std::string getImageFile () const;
    const Tile& getTile (const state::Element& e) const;
    // Setters and Getters
  };

};

#endif
