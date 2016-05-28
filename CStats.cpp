#include "CStats.h"

CStats::CStats()
{
	strength = 5;
	intelegence = 5;
	dexterity = 5;
}

int CStats::GetDexterity()
{
	return dexterity;
}
	
void CStats::SetDexterity(int _dexterity)
{
	dexterity = _dexterity;
}

void CStats::IncreaseDex()
{
	dexterity++;
}

int CStats::GetStrength()
{
	return strength;
}
	
void CStats::SetStrength(int _strength)
{
	strength = _strength;	
}

void CStats::IncreaseStr()
{
	strength++;
}

int CStats::GetIntelegence()
{
	return intelegence;
}
	
void CStats::SetIntelegence(int _intelegence)
{
	intelegence = _intelegence;
}

void CStats::IncreaseInt()
{
	intelegence++;
}