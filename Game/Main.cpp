#include "GameEngine.h"
#include "MovableQuad.h"
#include "PathFinding.h"

int main(int argc, char* argv[])
{
	GameEngine gameEngine = GameEngine(800, 600, "Vega");
	gameEngine.RegisterGameObject(std::make_unique<MovableQuad>(gameEngine, 48, 400, 800));
	//gameEngine.RegisterGameObject(std::make_unique<PathFinding>(gameEngine));
	int result = gameEngine.Run();
	return result;
}