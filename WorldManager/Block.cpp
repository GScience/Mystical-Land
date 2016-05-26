
#include "BlockManager.h"

//储存所有Block信息
std::unordered_map<std::string, blockType> BlockMap;

//添加一种Block类型
void addBlock(const blockType& BlockType, std::string BlockName)
{
	BlockMap.insert(std::pair<std::string, blockType>(BlockName, BlockType));
}

//获取Block的类型
const blockType& getBlockType(std::string BlockName)
{
	return BlockMap[BlockName];
}