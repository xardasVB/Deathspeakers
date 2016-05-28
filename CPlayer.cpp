#include "CPlayer.h"
#include <iostream>

using namespace std;

CPlayer::CPlayer(COORD basePosition)
{
	PlayerPosition = basePosition;
}

void CPlayer::MoveUp()
{
	PlayerPosition.Y -= 1;
}

COORD CPlayer::GetOneStepUp()
{
	COORD tmp = {PlayerPosition.X, PlayerPosition.Y - 1};
	return tmp;
}

void CPlayer::MoveDown()
{
	PlayerPosition.Y += 1;
}

COORD CPlayer::GetOneStepDown()
{
	COORD tmp = {PlayerPosition.X, PlayerPosition.Y + 1};
	return tmp;
}

void CPlayer::MoveLeft()
{
	PlayerPosition.X -= 1;
}

COORD CPlayer::GetOneStepLeft()
{
	COORD tmp = {PlayerPosition.X - 1, PlayerPosition.Y};
	return tmp;
}

void CPlayer::MoveRight()
{
	PlayerPosition.X += 1;
}

COORD CPlayer::GetOneStepRight()
{
	COORD tmp = {PlayerPosition.X + 1, PlayerPosition.Y};
	return tmp;
}

COORD CPlayer::GetPosition()
{
	return PlayerPosition;
}

void CPlayer::Spawn()
{
	SetCursorCoord(PlayerPosition.X, PlayerPosition.Y);
	cout << (char)1;
	SetCursorCoord(44, 28);
}

void CPlayer::Despawn()
{
	SetCursorCoord(PlayerPosition.X, PlayerPosition.Y);
	cout << " ";
	SetCursorCoord(44, 28);
}

void CPlayer::SetCursorCoord(short xPos, short yPos)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD position = { xPos, yPos };
	SetConsoleCursorPosition(hConsole, position);
}