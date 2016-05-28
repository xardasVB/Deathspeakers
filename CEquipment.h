#pragma once

#include "CItem.h"

class CEquipment
{
private:
	CItem* equipment;
public:
	CEquipment();

	CItem GetEquimpent();
	void SetEquimpent(CItem _Helmet);
	void SetEquimpent(char* _name, char* _type, int _count, char* _description);
};