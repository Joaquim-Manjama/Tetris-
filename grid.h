#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
	Grid();
	void Initialize();
	void Draw();
	bool isCellOutside(int row, int column);
	bool isCellEmpty(int row, int column);
	int grid[20][10];
private:
	int numRows;
	int numColumns;
	int cellSize;
	std::vector<Color> colors;
};
