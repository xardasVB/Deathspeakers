#pragma once
#include "Windows.h"
#include <iostream>

using namespace std;

class CMap
{
private:
	int col;
	int row;
	int **map;
	COORD PlayerBasePosition;

	int doorSize;
	COORD doorCoord;
	int location;
	COORD spawnCoord;

	enum { PATH = 0, WALL = 1, PLAYER = 2, DOOR = 3, ENEMY = 4, CHEST = 5, GUARD_NPC = 6};
public:
	CMap(char *file);
	void Print(COORD playerPosition);
	COORD GetPlayerBasePosition();
	int GetTargetObj(COORD position);
	void SetObj(COORD position, int obj);
	~CMap();
};