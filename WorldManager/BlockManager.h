#pragma once

#include "PositionManager.h"

#include <unordered_map>
#include <string>
#include <windows.h>

class block;
class blockType;

using std::string;

typedef void(*blockCall)(const unsigned __int16& BlockData);

extern std::unordered_map<string, blockType> BlockMap;

void				addBlock	(const blockType& BlockType, string BlockName);
const blockType&	getBlockType(string BlockName);

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
	uint16_t			BlockData;
	const blockType&	BlockType;

	void renderFallCall() { BlockType.renderCall(this->BlockData); }

public:
	block(const blockType& BlockType, __int16 BlockSubID, char Light) :BlockData((BlockSubID << 4) + Light), BlockType(BlockType) {}

	const blockType& getBlockType() { return BlockType; }

	uint16_t	getLight() { return BlockData >> 4; }
	uint16_t	getBlockSubID() { return (BlockData << 12) >> 12; }
};