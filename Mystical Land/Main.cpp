#include "..\WorldManager\WorldManager.h"

#include <sstream>
#include <limits>

int main()
{
	addBlock(blockType("Grass", (blockCall)22), "Grass");
	addBlock(blockType("Dirt", (blockCall)22), "Dirt");

	block TestBlock("Dirt", 0, 0);

	location Loc;

	Loc.moveTo(16.1, 1, -16);
	chunk_location CLoc = Loc;
}