
#include "PositionManager.h"

inline long double location::getX()
{
	return ChunkLocation.ChunkX * 16 + InChunkX;
}
inline long double location::getY()
{
	return ChunkLocation.ChunkY * 16 + InChunkY;
}
inline long double location::getZ()
{
	return ChunkLocation.ChunkZ * 16 + InChunkZ;
}
inline void location::moveTo(long double X, long double Y, long double Z)
{

}
inline void location::move(long double X, long double Y, long double Z)
{

}