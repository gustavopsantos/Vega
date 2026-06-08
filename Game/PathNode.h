#pragma once
#include <array>

class PathNode
{
public:
	PathNode(int x, int y) {
		X = x;
		Y = y;
	};

	PathNode* Connection = nullptr;
	int X;
	int Y;
	float G = 0;
	float H = 0;
	float F() 
	{
		return G + H;
	}
	bool Walkable = true;
};