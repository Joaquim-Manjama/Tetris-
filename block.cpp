#include "block.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;
}

void Block::Draw()
{
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void Block::Move(int rows, int columns)
{
	rowOffset += rows;
	columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles)
	{
		movedTiles.push_back(Position(item.row + rowOffset, item.column + columnOffset));
	}
	return movedTiles;
}

void Block::Rotate()
{
	rotationState = (rotationState + 1) % cells.size();
}

void Block::UndoRotation()
{
	rotationState = (rotationState - 1 ) % cells.size();
}
