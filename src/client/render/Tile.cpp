#include "Tile.h"

Tile::Tile (){}

Tile::Tile (int x, int y, int w, int h)
{
	this->x=x ;
	this-> y=y ;
	this-> widht = w ;
	this -> height = h;

}
    // Setters and Getters
int Tile::getHeight  () const
{
	return height ;
}
int getWidth () const
{
	return width ;
}
    int getX () const
    {
    	return x ;
    }
    int getY () const
    {
    	return y ;
    }
    void setHeight (int height)
    {
    	this -> height = height ;
    }
    void setWidth (int width)
    {
    	this -> height = height ;
    }
    void setX (int x)
    {
    	this -> x=x ;
    }
    void setY (int y)
    {
    	this -> y=y ;
    }
