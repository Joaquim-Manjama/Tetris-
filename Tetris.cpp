#include <raylib.h>
#include "grid.cpp"


int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Grid grid = Grid();

	while (WindowShouldClose() == false) 
	{
		BeginDrawing();
		ClearBackground(darkBlue);
		grid.Draw();

		EndDrawing();
	}


	CloseWindow();
	return 0;
}
