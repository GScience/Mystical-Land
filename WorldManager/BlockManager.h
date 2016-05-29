#pragma once

/**********************************************

Base Head File!Don't Base On Anything

***********************************************/

#include <unordered_map>
#include <string>

class block;
class blockType;

using std::string;

typedef void*(*blockCall)(const unsigned __int16& BlockData);

extern std::unordered_map<string, blockType> BlockTypeMap;

void	addBlock	(const blockType BlockType, string BlockName);	//Add a new blockType to BlockTypeMap

class blockType
{
	friend class block;

	//Basic Information(will add new thing in the future)
	string BlockName;

	//Render Infomation
	blockCall renderCall;
public:
	blockType::blockType(string BlockName, blockCall renderCall) :BlockName(BlockName),renderCall(renderCall) {}

	blockType() = default;
};

class block
{
public:
	const blockType*	BlockType;

private:
	uint16_t*	BlockData;

	void* renderCall() { return BlockType->renderCall(*BlockData); }

	block(const blockType& BlockType, uint16_t* BlockData) :BlockData(BlockData), BlockType(&BlockType) {}

public:

	block(string BlockTypeName, uint16_t BlockSubID, char Light) :BlockData(new uint16_t(BlockSubID << 4) + Light), BlockType(&BlockTypeMap[BlockTypeName]) {}

	const blockType& getMaterial() { return *BlockType; }

	uint16_t	getLight() { return *BlockData >> 4; }
	uint16_t	getBlockSubID() { return (*BlockData << 12) >> 12; }

	void setMaterial(string BlockTypeName) 
	{
		BlockType = &BlockTypeMap[BlockTypeName];
	}
};