#include "GameEngine.h"
#include "MovableQuad.h"

int main(int argc, char* argv[])
{
	GameEngine gameEngine = GameEngine(800, 600, "Vega");
	gameEngine.RegisterGameObject(std::make_unique<MovableQuad>(gameEngine, 48, 400, 800));
	int result = gameEngine.Run();
	return result;
}