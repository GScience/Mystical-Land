
#include "BlockManager.h"

std::unordered_map<std::string, blockType> BlockMap;

//��ȡBlock����
inline const blockType& block::getBlockType()
{
	return BlockType;
}
//��ȡ����
inline unsigned char block::getLight()
{
	return BlockData << 28 >> 28;
}
//��ȡ������ID
inline unsigned __int16 block::getBlockSubID()
{
	return BlockData << 16 >> 20;
}
inline void block::itemFallCall()
{
	BlockType.itemFallCall(this->BlockData);
}
inline void block::renderFallCall()
{
	BlockType.renderCall(this->BlockData);
}