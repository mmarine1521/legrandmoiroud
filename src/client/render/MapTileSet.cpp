#include "MapTileSet.h"

namespace render{

	MapTileSet::MapTileSet()
	{
		
	}
	
	int const MapTileSet::getCellWidth()
	{
		return 768 ; 
	}
	int const MapTileSet::getCellHeight()
	{
		return 864 ; 
	}
	
	const std::string MapTileSet::getImageFile() const
	{
		return "res/tank384px.png"; 
	}
	
}
