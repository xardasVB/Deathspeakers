#pragma once

#include "CItem.h"
#include "InvFunctions.h"
class CInventory
{
	int sizeOfInventory;
	CItem* inventory;
public:
	CInventory();

	CItem* GetInventory();
	void SetInventory(CItem* _inventory);

	int GetSize();
	void SetSize(int _size);

	void IncreaseSize();
	void DecreaseSize();

	void AddItem(CItem _item);
	void RemoveItem(CItem _item);

	~CInventory();
};