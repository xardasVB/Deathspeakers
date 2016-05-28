#pragma once

class CItem
{
	char* name;
	char* type;
	char* description;
	int count;
public:
	CItem();
	CItem(char* _name, char* _type, char* _description);
	CItem(CItem* obj);
	char* GetName();
	void SetName(char* _name);

	char* GetType();
	void SetType(char* _name);

	char* GetDescription();
	void SetDescription(char* _name);

	int GetCount();
	void SetCount(int _count);

	void IncreaseCount();
	void DecreaseCount();
private:
	char* Trim(char* oldString);
public:
	~CItem();

};