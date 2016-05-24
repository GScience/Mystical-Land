#pragma once

#include "PositionManager.h"

#include <unordered_map>
#include <string>

//Block�е��õĺ���
typedef void(*blockCall)(const unsigned __int16& BlockData);

//���𴢴�һ��Block����Ϣ
struct blockType
{
	//�������
	blockCall itemFallCall;

	//��Ⱦ���
	blockCall renderCall;

	//���캯��
	blockType(blockCall itemFallCall, blockCall renderCall) :itemFallCall(itemFallCall),renderCall(renderCall) {}
	blockType() = default;
};

//���𴢴�һ��Block����Ϣ��һ�������Ͳ��ɸ��ģ�
class block
{
	//���𴢴�Block��������Ϣ��������0001�У�����0��ʾBlock����ID��1��ʾ����
	const unsigned __int16 BlockData;

	//����Block������
	const blockType& BlockType;

public:
	//���캯��
	block(const blockType& BlockType, __int16 BlockSubID, char Light) :BlockData((BlockSubID << 4) + Light), BlockType(BlockType) {}

	//��ȡBlock����
	const blockType& getBlockType();

	//��ȡ����
	unsigned char getLight();

	//��ȡ������ID
	unsigned __int16 getBlockSubID();

	//�������غ���
	void itemFallCall();
	void renderFallCall();
};

//����Block���͵Ĵ洢λ��
extern std::unordered_map<std::string, blockType> BlockMap;

//���һ��Block����
inline void addBlock(const blockType& BlockType, std::string BlockName)
{
	BlockMap.insert(std::pair<std::string, blockType>(BlockName, BlockType));
}

//��ȡBlock������
inline const blockType& getBlockType(std::string BlockName)
{
	return blockType(BlockMap[BlockName]);
}