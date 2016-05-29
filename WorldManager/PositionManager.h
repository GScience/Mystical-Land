#pragma once

/**********************************************

	Base Head File!Don't Base On Anything

***********************************************/

//Chunk position
class chunk_location
{
	__int64 ChunkX;
	__int64 ChunkY;
	__int64 ChunkZ;

public:
	chunk_location(__int64 ChunkX, __int64 ChunkY, __int64 ChunkZ) :ChunkX(ChunkX), ChunkY(ChunkY), ChunkZ(ChunkZ) { }

	inline __int64 getChunkX()
	{
		return ChunkX;
	}
	inline __int64 getChunkY()
	{
		return ChunkY;
	}
	inline __int64 getChunkZ()
	{
		return ChunkZ;
	}
};

//Block position
class block_location
{
	//in chunk position
	unsigned int X : 4;
	unsigned int Y : 4;
	unsigned int Z : 4;

	//chunk position
	chunk_location ChunkLocation;

public:
	block_location(short Location, chunk_location ChunkLocation) :Location(Location), ChunkLocation(ChunkLocation) {}

	chunk_location gelChunkLocation()
	{
		return ChunkLocation;
	}
};

//Basic Locaiton
class location
{
	double X = 0.0;
	double Y = 0.0;
	double Z = 0.0;

public:
	location() = default;
	location(const double& X, const double& Y, const double& Z) :X(X), Y(Y), Z(Z) {}

	//Get location
	double getX()
	{
		return X;
	}
	double getY()
	{
		return Y;
	}
	double getZ()
	{
		return Z;
	}

	//move
	void move(const double& XMov, const double& YMov, const double& ZMov)
	{
		X += XMov;
		Y += YMov;
		Z += ZMov;
	}
	void moveTo(const double& XPos, const double& YPos, const double& ZPos)
	{
		X = XPos;
		Y = YPos;
		Z = ZPos;
	}

	//convern
	operator chunk_location()
	{
		return chunk_location(	X > 0 ? (__int64)(X / 16) : (__int64)(X / 16) - 1,
								Y > 0 ? (__int64)(Y / 16) : (__int64)(Y / 16) - 1,
								Z > 0 ? (__int64)(Z / 16) : (__int64)(Z / 16) - 1);
	}
	operator block_location()
	{
		return block_location(0, (chunk_location)*this);
	}
};