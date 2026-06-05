#include "Engine.h"

int main(int argc, char* argv[])
{
	GameEngine gameEngine = GameEngine(800, 600, "Vega");
	int result = gameEngine.Run();
	return result;
}