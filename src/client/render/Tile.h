// Generated by dia2code
#ifndef RENDER__TILE__H
#define RENDER__TILE__H


namespace render {

  /// class Tile - 
  class Tile {
    // Attributes
  public:
    int height     = 16;
  protected:
    int x     = 0;
    /// 													
    int y     = 0;
    int width     = 16;
    // Operations
  public:
    Tile ();
    Tile (int x, int y, int w, int h);
    virtual ~Tile ();
    int getHeight  () const;
    int getWidth () const;
    int getX () const;
    int getY () const;
    void setHeight (int height);
    void setWidth (int width);
    void setX (int x);
    void setY (int y);
    // Setters and Getters
  };

};

#endif
