#pragma once

#include "Windows.h"

class CPlayer
{
private:
	COORD PlayerPosition;
	int health;
public:
	CPlayer(COORD basePosition);	
	void MoveUp();
	COORD GetOneStepUp();

	void MoveDown();
	COORD GetOneStepDown();

	void MoveLeft();
	COORD GetOneStepLeft();

	void MoveRight();
	COORD GetOneStepRight();

	COORD GetPosition();

	void Despawn();
	void Spawn();
	void SetCursorCoord(short xPos, short yPos);
};



