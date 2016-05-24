#pragma once

#include "ChunkManager.h"

//区块位置类
struct chunk_location
{
	__int32 ChunkX;
	__int32 ChunkY;
	__int32 ChunkZ;
};

//位置类
class location
{
	//所在Chunk坐标
	chunk_location ChunkLocation;
	
	//相对于Chunk的位置（记Chunk的一角为原点）
	double InChunkX;
	double InChunkY;
	double InChunkZ;
public:
	//获取位置
	long double getX();
	long double getY();
	long double getZ();

	//移动
	void move(long double, long double, long double);
	void moveTo(long double, long double, long double);

	//所在Chunk位置
};