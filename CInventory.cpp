#include "CInventory.h"
#include <iostream>

using namespace std;

CInventory::CInventory()
{
	sizeOfInventory = 0; 
	inventory = new CItem[sizeOfInventory];
}

CItem* CInventory::GetInventory()
{
	return inventory;
}

void CInventory::SetInventory(CItem* _inventory)
{
	inventory = _inventory;
}

int CInventory::GetSize()
{
	return sizeOfInventory;
}

void CInventory::SetSize(int _size)
{
	sizeOfInventory = _size;
}

void CInventory::IncreaseSize()
{
	sizeOfInventory++;
}

void CInventory::DecreaseSize()
{
	sizeOfInventory--;
}

void CInventory::AddItem(CItem _item)
{
	bool active = true;
	for (int i = 0; i < sizeOfInventory; i++)
	{
		if (strcmp(GetInventory()[i].GetName(), _item.GetName()) == 0)
		{
			GetInventory()[i].IncreaseCount();
			active = false;
		}
	}
	
	if(active)
	{
		AddElement(inventory, sizeOfInventory, sizeOfInventory - 1, _item);
	}
}

void CInventory::RemoveItem(CItem _item)
{
	int position;
	for (int i = 0; i < sizeOfInventory; i++)
	{
		if (strcmp(GetInventory()[i].GetName(), _item.GetName()) == 0)
		{
			position = i;
			if (GetInventory()[i].GetCount() == 1)
			{
				RemoveElement(inventory, sizeOfInventory, position);
			}
			else
			{
				GetInventory()[i].DecreaseCount();
			}
		}
	}	
}

CInventory::~CInventory()
{
	delete[] inventory;
}
