
#include "BlockManager.h"

std::unordered_map<std::string, blockType> BlockTypeMap;

void addBlock(const blockType BlockType, string BlockName)
{
	BlockTypeMap.insert(std::pair<std::string, blockType>(BlockName, BlockType));
}