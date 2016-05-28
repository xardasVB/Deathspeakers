#include "CItem.h"
#include <cstring>


CItem::CItem()
{

}

CItem::CItem(char* _name, char* _type, char* _description) 
{ 
	name = Trim(_name); 
	type = Trim(_type); 
	description = Trim(_description); 
	count = 1;
}

CItem::CItem(CItem* obj)
{
	name = Trim(obj->GetName()); 
	type = Trim(obj->GetType()); 
	description = Trim(obj->GetDescription());
	count = obj->count;
}

char* CItem::GetName()
{
	return name;
}
	
void CItem::SetName(char* _name)
{
	name = Trim(_name); 
}

char* CItem::GetType()
{
	return type;
}
	
void CItem::SetType(char* _type)
{
	type = Trim(_type); 	
}

char* CItem::GetDescription()
{
	return description;
}
	
void CItem::SetDescription(char* _description)
{
	description = Trim(_description); 
}

int CItem::GetCount()
{
	return count;
}

void CItem::SetCount(int _count)
{
	count = _count;
}

void CItem::IncreaseCount()
{
	count += 1;
}

void CItem::DecreaseCount()
{
	count -= 1;
}

char* CItem::Trim(char* oldString)
{
	int lenght = strlen(oldString) + 1;
	char* newString = new char[lenght];
	strcpy_s(newString, lenght, oldString);
	return newString;
}

CItem::~CItem()
{
	//delete[] name;
	//delete[] type;
	//delete[] description;
}

