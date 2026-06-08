#include "PathFinding.h"
#include "GameEngine.h"
#include <unordered_set>
#include <cassert>

void PathFinding::Start()
{
	for (int y = 0; y < GRID_SIZE; y++)
	{
		for (int x = 0; x < GRID_SIZE; x++)
		{
			grid[x][y] = new PathNode(x, y);
		}
	}
}

void PathFinding::Update()
{
	auto inputManager = GetEngine().m_InputManager;

	if (inputManager.WasButtonPressed(SDL_BUTTON_LEFT))
	{
		int x = inputManager.mousePositionX / CELL_SIZE;
		int y = inputManager.mousePositionY / CELL_SIZE;

		PathNode* pathNode = grid[x][y];
		pathNode->Walkable = !pathNode->Walkable;
	}

	if (inputManager.WasKeyPressed(SDLK_C))
	{
		mVisited.clear();
		mFoundPath.clear();
	}

	if (inputManager.WasKeyPressed(SDLK_SPACE))
	{
		mVisited.clear();
		mFoundPath.clear();
		auto start = grid[1][1];
		auto target = grid[14][14];
		FindPath(start, target, mFoundPath);
	}
}

void PathFinding::Render()
{
	for (int y = 0; y < GRID_SIZE; y++)
	{
		for (int x = 0; x < GRID_SIZE; x++)
		{
			SDL_Color cellColor = GetCellColor(x, y);
			DrawCell(x, y, cellColor);
		}
	}

	if (!mVisited.empty())
	{
		for (PathNode* pathNode : mVisited)
		{
			DrawCell(pathNode->X, pathNode->Y, VISITED_COLOR);
		}
	}

	if (!mFoundPath.empty())
	{
		for (PathNode* pathNode : mFoundPath)
		{
			DrawCell(pathNode->X, pathNode->Y, PATH_COLOR);
		}
	}

	DrawCell(1, 1, START_COLOR);
	DrawCell(GRID_SIZE - 2, GRID_SIZE - 2, TARGET_COLOR);
}

int PathFinding::CalculateGridDistance(PathNode* a, PathNode* b)
{
	int x1 = a->X;
	int y1 = a->Y;

	int x2 = b->X;
	int y2 = b->Y;

	int dx = std::abs(x1 - x2);
	int dy = std::abs(y1 - y2);

	int diagonal = std::min(dx, dy);
	int straight = std::abs(dx - dy);

	return diagonal * 14 + straight * 10;
}

bool PathFinding::FindPath(PathNode* start, PathNode* target, std::vector<PathNode*>& path)
{
	assert(target != nullptr);
	std::unordered_set<PathNode*> toSearch = std::unordered_set<PathNode*>();
	std::unordered_set<PathNode*> processed = std::unordered_set<PathNode*>();

	toSearch.insert(start);

	while (!toSearch.empty())
	{
		PathNode* current = nullptr;

		for (PathNode* t : toSearch)
		{
			if (current == nullptr || t->F() < current->F() || (t->F() == current->F() && t->H < current->H))
			{
				current = t;
			}
		}

		mVisited.push_back(current);
		processed.insert(current);
		toSearch.erase(current);

		if (current == target)
		{
			PathNode* currentPathTile = target;
			
			while (currentPathTile != start)
			{
				path.push_back(currentPathTile);
				currentPathTile = currentPathTile->Connection;
			}
			return true;
		}

		auto neighbors = GetNeighbors(current);
		for (PathNode* neighbor : neighbors)
		{
			if (!neighbor->Walkable || processed.contains(neighbor))
			{
				continue;
			}

			bool inSearch = toSearch.contains(neighbor);
			int costToNeighbor = current->G + CalculateGridDistance(current, neighbor);

			if (!inSearch || costToNeighbor < neighbor->G)
			{
				neighbor->G = costToNeighbor;
				neighbor->Connection = current;

				if (!inSearch)
				{
					neighbor->H = CalculateGridDistance(neighbor, target);
					toSearch.insert(neighbor);
				}
			}
		}
	}

	return false;
}

bool PathFinding::TryGetPathNode(Vector2 pos, PathNode*& pathNode)
{
	int x = pos.x;
	int y = pos.y;

	if (x < 0 || x >= GRID_SIZE)
	{
		return false;
	}

	if (y < 0 || y >= GRID_SIZE)
	{
		return false;
	}

	pathNode = grid[x][y];
	return true;
}

std::vector<PathNode*> PathFinding::GetNeighbors(PathNode* pathNode)
{
	auto neighbors = std::vector<PathNode*>();

	int x = pathNode->X;
	int y = pathNode->Y;

	auto north     = Vector2(x,     y - 1);
	auto northEast = Vector2(x + 1, y - 1);
	auto east      = Vector2(x + 1, y);
	auto southEast = Vector2(x + 1, y + 1);
	auto south     = Vector2(x,     y + 1);
	auto southWest = Vector2(x - 1, y + 1);
	auto west      = Vector2(x - 1, y);
	auto northWest = Vector2(x - 1, y - 1);

	PathNode* node = nullptr;
	if (TryGetPathNode(north, node)) neighbors.push_back(node);
	if (TryGetPathNode(northEast, node)) neighbors.push_back(node);
	if (TryGetPathNode(east, node)) neighbors.push_back(node);
	if (TryGetPathNode(southEast, node)) neighbors.push_back(node);
	if (TryGetPathNode(south, node)) neighbors.push_back(node);
	if (TryGetPathNode(southWest, node)) neighbors.push_back(node);
	if (TryGetPathNode(west, node)) neighbors.push_back(node);
	if (TryGetPathNode(northWest, node)) neighbors.push_back(node);

	return neighbors;
}

SDL_Color PathFinding::GetCellColor(int x, int y) const
{
	PathNode* pathNode = grid[x][y];

	return pathNode->Walkable 
		? TRAVERSABLE_COLOR
		: UNTRAVERSABLE_COLOR;
}

void PathFinding::DrawCell(int x, int y, SDL_Color color) const
{
	SDL_FRect border = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE };
	SDL_SetRenderDrawColor(GetEngine().m_Renderer, BORDER_COLOR.r, BORDER_COLOR.g, BORDER_COLOR.b, BORDER_COLOR.a);
	SDL_RenderFillRect(GetEngine().m_Renderer, &border);

	SDL_FRect inner = { x * CELL_SIZE + CELL_BORDER, y * CELL_SIZE + CELL_BORDER, CELL_SIZE - (CELL_BORDER * 2), CELL_SIZE - (CELL_BORDER * 2) };
	SDL_SetRenderDrawColor(GetEngine().m_Renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(GetEngine().m_Renderer, &inner);
}
