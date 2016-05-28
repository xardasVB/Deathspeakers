#pragma once

class CStats
{
	int dexterity;
	int strength;
	int intelegence;
public:
	CStats();
	int GetDexterity();
	void SetDexterity(int _dexterity);
	void IncreaseDex();

	int GetStrength();
	void SetStrength(int _strength);
	void IncreaseStr();

	int GetIntelegence();
	void SetIntelegence(int _intelegence);
	void IncreaseInt();
};