#include "StateTileSet.h"

namespace render{

	StateTileSet::StateTileSet()
	{
		
	}
	
	int const StateTileSet::getCellWidth()
	{
		return 768 ; 
	}
	int const StateTileSet::getCellHeight()
	{
		return 864 ; 
	}
	
	const std::string StateTileSet::getImageFile() const 
	{
		return "res/tank384px.png"; 
	}
	
}
