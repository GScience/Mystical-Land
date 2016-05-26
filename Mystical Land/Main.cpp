#include "..\WorldManager\WorldManager.h"

#include <sstream>

int main()
{
	for (int i = 0; i < 1000; i++)
	{
		addBlock(blockType("²âÊÔ", (blockCall)22), std::to_string(i));

	}
	for (int j = 0; j < 1000; j++)
	{
		for (int i = 0; i < 1000; i++)
		{
			blockType BT = getBlockType(std::to_string(i));
		}
	}
}