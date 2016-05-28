#include "CMap.h"
#include <fstream>
#include "CGame.h"

CMap::CMap(char *file)
{
	ifstream fin(file);
	
	if (fin)
	{
		fin >> row;
		fin >> col;

		fin >> PlayerBasePosition.X;
		fin >> PlayerBasePosition.Y;

		map = new int*[row];
		for (int i = 0; i < row; i++)
		{
			map[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fin >> map[i][j];
			}
		}

		fin.close();
	}
	else
	{
		cout << "can't load " << file << " map file" << endl;
	}
}


void CMap::Print(COORD playerPosition)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi); 

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == playerPosition.Y && j == playerPosition.X)
			{
				SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
				cout << (char)1;
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
			else 
			{
				switch (map[i][j])
				{
				case WALL:
					SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN );
					cout << ' ';
					SetConsoleTextAttribute(hConsole, csbi.wAttributes);
					break;
				case PATH:
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
					cout << " ";
					SetConsoleTextAttribute(hConsole, csbi.wAttributes);
					break;
				case DOOR:
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN);
					cout << "#";
					SetConsoleTextAttribute(hConsole, csbi.wAttributes);
					break;
				case ENEMY:
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | FOREGROUND_RED);
					cout << (char)30;
					SetConsoleTextAttribute(hConsole, csbi.wAttributes);
					break;
				case CHEST:
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
					cout << "m";
					SetConsoleTextAttribute(hConsole, csbi.wAttributes);
					break;
				case GUARD_NPC:
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN );
					cout << (char)2;
					SetConsoleTextAttribute(hConsole, csbi.wAttributes);
					break;
				}
			}
		}
		cout << endl;
	}
}

COORD CMap::GetPlayerBasePosition()
{
	return PlayerBasePosition;
}

int CMap::GetTargetObj(COORD position)
{
	return map[position.Y][position.X];
}

void CMap::SetObj(COORD position, int obj)
{
	map[position.Y][position.X] = obj;
}

CMap::~CMap()
{
	for (int i = 0; i < row; i++)
	{
		delete[] map[i];
	}	
	delete[] map;
}