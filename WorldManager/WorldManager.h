#pragma once

#include <string>

using std::string;

typedef void(*blockCall)(const unsigned __int16& BlockData);

class blockType
{
	friend class block;

	//Basic Information(will add new thing in the future)
	string BlockName;

	//Render Infomation
	blockCall renderCall;
public:
	blockType::blockType(string BlockName, blockCall renderCall) :BlockName(BlockName), renderCall(renderCall) {}

	blockType();
};

class block
{
	uint16_t			BlockData;
	const blockType&	BlockType;

	void renderFallCall() { BlockType.renderCall(this->BlockData); }
	
public:
	block(const blockType& BlockType, __int16 BlockSubID, char Light);

	const blockType& getBlockType() { return BlockType; }

	uint16_t	getLight() { return BlockData >> 4; }
	uint16_t	getBlockSubID() { return (BlockData << 12) >> 12; }
};

void	addBlock(const blockType& BlockType, std::string BlockName);
const	blockType& getBlockType(std::string BlockName);
