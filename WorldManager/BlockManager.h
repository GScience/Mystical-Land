#pragma once

#include "PositionManager.h"

#include <unordered_map>
#include <string>

//Block中调用的函数
typedef void(*blockCall)(const unsigned __int16& BlockData);

//负责储存一类Block的信息
struct blockType
{
	//掉落相关
	blockCall itemFallCall;

	//渲染相关
	blockCall renderCall;

	//构造函数
	blockType(blockCall itemFallCall, blockCall renderCall) :itemFallCall(itemFallCall),renderCall(renderCall) {}
	blockType() = default;
};

//负责储存一个Block的信息（一旦创建就不可更改）
class block
{
	//负责储存Block的所有信息，例如在0001中，所有0表示Block的子ID，1表示亮度
	const unsigned __int16 BlockData;

	//储存Block的类型
	const blockType& BlockType;

public:
	//构造函数
	block(const blockType& BlockType, __int16 BlockSubID, char Light) :BlockData((BlockSubID << 4) + Light), BlockType(BlockType) {}

	//获取Block类型
	const blockType& getBlockType();

	//获取亮度
	unsigned char getLight();

	//获取方块子ID
	unsigned __int16 getBlockSubID();

	//方块的相关函数
	void itemFallCall();
	void renderFallCall();
};

//所有Block类型的存储位置
extern std::unordered_map<std::string, blockType> BlockMap;

//添加一种Block类型
inline void addBlock(const blockType& BlockType, std::string BlockName)
{
	BlockMap.insert(std::pair<std::string, blockType>(BlockName, BlockType));
}

//获取Block的类型
inline const blockType& getBlockType(std::string BlockName)
{
	return blockType(BlockMap[BlockName]);
}