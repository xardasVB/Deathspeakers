#pragma once
#include "CEquipment.h"
#include "CInventory.h"
#include "CStats.h"
#include "CMap.h"
#include "CPlayer.h"

using namespace std;

class CGame
{
	CEquipment equipment;
	CInventory inventory;
	CStats stats;
	CMap *map;
	CPlayer *player;
	int location;
	int health;
	bool MenuActive;
	bool gameStartActive;
public:
	CGame();
	void Load(char* file, CItem** &items, int &inventorySize) ;
	void PrintEquipmentInventory();

	void Menu();
	void Battle();
	void Dialog();

	int GetHealth();
	void SetHealth(int _health);

	void PlayGame();	
	void RandChestItem(CItem** items);

	void NewLocation();

	~CGame();
};


