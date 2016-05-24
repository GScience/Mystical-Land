#pragma once

#include "ChunkManager.h"

//����λ����
struct chunk_location
{
	__int32 ChunkX;
	__int32 ChunkY;
	__int32 ChunkZ;
};

//λ����
class location
{
	//����Chunk����
	chunk_location ChunkLocation;
	
	//�����Chunk��λ�ã���Chunk��һ��Ϊԭ�㣩
	double InChunkX;
	double InChunkY;
	double InChunkZ;
public:
	//��ȡλ��
	long double getX();
	long double getY();
	long double getZ();

	//�ƶ�
	void move(long double, long double, long double);
	void moveTo(long double, long double, long double);

	//����Chunkλ��
};