#include "CEquipment.h"

CEquipment::CEquipment()
{
		
	Helmet.SetName("None");
	Helmet.SetCount(1);
	Helmet.SetDescription(" ");
	

	Helmet.SetType("Helmet");
}

CItem CEquipment::GetEquipment()
{
	return Helmet;
}

void CEquipment::SetEquipment(CItem _Helmet)
{
	Helmet = _Helmet;
	Helmet.SetCount(1);
}

void CEquipment::SetEquipment(char * _name, char * _type, int _count, char * _description)
{
	Helmet.SetName(_name);
	Helmet.SetCount(_count);
	Helmet.SetDescription(_description);
	Helmet.SetType(_type);
}
