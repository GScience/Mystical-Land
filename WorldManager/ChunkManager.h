#pragma once

/**********************************************

	Base On PositionManager and BlockManager

***********************************************/

#include "PositionManager.h"
#include "BlockManager.h"

//Chunk
class chunk
{
	block* Blocks[16][16][16];

	chunk_location Location;

public:
	void inline getBlock(unsigned __int16 Location)
	{
		
	}
};