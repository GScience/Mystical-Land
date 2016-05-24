#include "..\WorldManager\BlockManager.h"

#include <sstream>

std::unordered_map<std::string, blockType> BlockMap;

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		std::stringstream SS;
		SS << i;

		addBlock(blockType((blockCall)11, (blockCall)22), SS.str().c_str());
		blockType BT = getBlockType(SS.str().c_str());

		if (BT.itemFallCall == NULL)
			return -1;
	}
}