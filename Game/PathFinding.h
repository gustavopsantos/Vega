#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "PathNode.h"

#include <vector>
#include <SDL3/SDL.h>


class PathFinding : public GameObject
{
	static constexpr SDL_Color START_COLOR{ 159,254,9,255 };
	static constexpr SDL_Color TARGET_COLOR{ 255,48,50,255 };
	static constexpr SDL_Color TRAVERSABLE_COLOR{ 18,18,18,255 };
	static constexpr SDL_Color UNTRAVERSABLE_COLOR{ 66,66,66,255 };
	static constexpr SDL_Color VISITED_COLOR{ 21,130,255,255 };
	static constexpr SDL_Color PATH_COLOR{ 254,254,0,255 };
	static constexpr SDL_Color BORDER_COLOR{ 29,29,29,255 };

public:
	static const int GRID_SIZE = 16;
	static const int CELL_SIZE = 32;
	static const int CELL_BORDER = 2;
	PathFinding(GameEngine& engine) : GameObject(engine)
	{}
	void Start() override;
	void Update() override;
	void Render() override;

	bool FindPath(PathNode* start, PathNode* target, std::vector<PathNode*>& path);
	static int CalculateGridDistance(PathNode* a, PathNode* b);

private:
	bool TryGetPathNode(Vector2 pos, PathNode*& pathNode);
	std::vector<PathNode*> GetNeighbors(PathNode* pathNode);
	SDL_Color GetCellColor(int x, int y) const;
	void DrawCell(int x, int y, SDL_Color color) const;
	PathNode* grid[GRID_SIZE][GRID_SIZE] = {};

	std::vector<PathNode*> mFoundPath = std::vector<PathNode*>();
	std::vector<PathNode*> mVisited = std::vector<PathNode*>();
};