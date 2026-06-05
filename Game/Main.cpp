#include "Engine.h"

int main(int argc, char* argv[])
{
	GameEngine gameEngine = GameEngine();
	int result = gameEngine.Run();
	return result;
}