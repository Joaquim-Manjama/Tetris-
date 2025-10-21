#include <raylib.h>
#include "game.cpp"

double lastUpdateTime = 0;

bool EventTriggered(double interval);

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Game game = Game();

	while (WindowShouldClose() == false) 
	{
		//Event Handling
		game.HandleInput();

		//Update
		if(EventTriggered(0.2))
		{
			game.MoveBlockDown();
		}

		//Draw
		BeginDrawing();
		ClearBackground(darkBlue);
		game.Draw();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}
