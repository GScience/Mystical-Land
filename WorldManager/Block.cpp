
#include "BlockManager.h"

//��������Block��Ϣ
std::unordered_map<std::string, blockType> BlockMap;

//���һ��Block����
void addBlock(const blockType& BlockType, std::string BlockName)
{
	BlockMap.insert(std::pair<std::string, blockType>(BlockName, BlockType));
}

//��ȡBlock������
const blockType& getBlockType(std::string BlockName)
{
	return BlockMap[BlockName];
}