#include "CGame.h"
#include "GameFunctions.h"
#include <fstream>
#include <ctime>
#include <conio.h>

CGame::CGame()
{
	health = 100;
	MenuActive = true;
	gameStartActive = false;

	while (MenuActive)
	{
		map = new CMap("maps/map_3.txt");
		player = new CPlayer(map->GetPlayerBasePosition());
		location = 1;

		Menu();
	}
}

void CGame::Load(char* file, CItem** &items, int &itemsSize)
{
	ifstream fin(file);

	if (fin)
	{
		char *tmp = new char[2];
		fin >> itemsSize;
		fin.getline(tmp, 2, '\n');
		items = new CItem*[itemsSize];
		for (int i = 0; i < itemsSize; i++)
		{
			char* nameBuffer = new char[256];
			fin.getline(nameBuffer, 256, '\n');

			char* typeBuffer = new char[256];
			fin.getline(typeBuffer, 256, '\n');

			char* descriptionBuffer = new char[256];
			fin.getline(descriptionBuffer, 256, '\n');

			items[i] = new CItem(nameBuffer, typeBuffer, descriptionBuffer);

			delete[] nameBuffer;
			delete[] typeBuffer;
			delete[] descriptionBuffer;
		}

		fin.close();
	}
	else
	{
		cout << "can't open file" << endl;
	}
}

void CGame::PrintEquipmentInventory()
{
	int itemsSize;
	CItem** items;
	Load("items.txt", items, itemsSize);

	bool active = true;
	enum {UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, TAB = 9, ESCAPE = 27, ENTER = 13};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	int ForNumb = 3;
	int activeMenuItem = 0;
	int menuItemsCount = inventory.GetSize();
	int lastMenuItem = menuItemsCount - 1;
	int activeTableItem = 1;

	Background();
	while (active)
	{
		//print inventory
		//hide wall of code
		if (true)
		{
			SetCursorPosition(16, 5);
			cout << "Helmet: ";
			cout << "                ";
			SetCursorPosition(16, 6);
			cout << "Cuirass: ";
			cout << "               ";
			SetCursorPosition(16, 7);
			cout << "Leggins: ";
			cout << "               ";
			SetCursorPosition(16, 8);
			cout << "Boots: ";
			cout << "                 ";
			SetCursorPosition(16, 9);
			cout << "Weapon: ";
			cout << "                ";
			SetCursorPosition(16, 10);
			cout << "Shield: ";
			cout << "                ";

			SetCursorPosition(16, 4);
			cout << "       Equipment";
			SetCursorPosition(16, 5);
			cout << "Helmet: ";
			if (activeMenuItem == 0 && activeTableItem == 0)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << equipment.GetHelmet().GetName();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			SetCursorPosition(16, 6);
			cout << "Cuirass: ";
			if (activeMenuItem == 1 && activeTableItem == 0)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << equipment.GetCuirass().GetName();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			SetCursorPosition(16, 7);
			cout << "Leggins: ";
			if (activeMenuItem == 2 && activeTableItem == 0)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << equipment.GetLeggins().GetName();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			SetCursorPosition(16, 8);
			cout << "Boots: ";
			if (activeMenuItem == 3 && activeTableItem == 0)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << equipment.GetBoots().GetName();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			SetCursorPosition(16, 9);
			cout << "Weapon: ";
			if (activeMenuItem == 4 && activeTableItem == 0)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << equipment.GetWeapon().GetName();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			SetCursorPosition(16, 10);
			cout << "Shield: ";
			if (activeMenuItem == 5 && activeTableItem == 0)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << equipment.GetShield().GetName();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			
			SetCursorPosition(16, 12);
			cout << "       Stats";
			SetCursorPosition(16, 13);
			cout << "Strength: ";
			if (activeMenuItem == 0 && activeTableItem == 3)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << stats.GetStrength();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			SetCursorPosition(16, 14);
			cout << "Dexterity: ";
			if (activeMenuItem == 1 && activeTableItem == 3)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << stats.GetDexterity();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			SetCursorPosition(16, 15);
			cout << "Intelegence: ";
			if (activeMenuItem == 2 && activeTableItem == 3)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << stats.GetIntelegence();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);

			SetCursorPosition(16, 17);
			cout << "Health: ";
			cout << GetHealth();
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			
			SetCursorPosition(42, 4);
			cout << "      Inventory";

			ForNumb = 5;
			for (int i = 0; i < 19; i++)
			{
				SetCursorPosition(42, ForNumb++);
				cout << "                        ";
			}

			ForNumb = 5;
			for (int i = 0; i < inventory.GetSize(); i++)
			{
				if (i == activeMenuItem && activeTableItem == 1)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				}
				SetCursorPosition(42, ForNumb++);
				cout << inventory.GetInventory()[i].GetName();
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}

			if (inventory.GetSize() == 0 && activeTableItem == 1)
			{
				SetCursorPosition(67, 4);
				cout << "                        ";
				SetCursorPosition(67, 6);
				cout << "                        ";
				SetCursorPosition(67, 8);
				cout << "                        ";
				SetCursorPosition(67, 10);
			}
			else if (inventory.GetSize() > 0 && activeTableItem == 1)
			{
				SetCursorPosition(67, 4);
				cout << "                        ";
				SetCursorPosition(67, 4);
				cout << inventory.GetInventory()[activeMenuItem].GetName();
				SetCursorPosition(67, 6);
				cout << "                        ";
				SetCursorPosition(67, 6);
				cout << "Count: " << inventory.GetInventory()[activeMenuItem].GetCount();
				SetCursorPosition(67, 8);
				cout << "                        ";
				SetCursorPosition(67, 8);
				cout << inventory.GetInventory()[activeMenuItem].GetType();
				SetCursorPosition(67, 10);


				ForNumb = 10;
				for (int i = 0; i < 150; i++)
				{
					if (i % 24 == 0)
					{
						SetCursorPosition(67, ForNumb);
						ForNumb++;
					}
					cout << " ";
				}

				ForNumb = 10;
				for (int i = 0; inventory.GetInventory()[activeMenuItem].GetDescription()[i] != '\0'; i++)
				{
					if (i % 24 == 0)
					{
						SetCursorPosition(67, ForNumb);
						ForNumb++;
					}
					cout << inventory.GetInventory()[activeMenuItem].GetDescription()[i];
				}
			}
			else if (activeTableItem == 0)
			{
				switch (activeMenuItem)
				{
				case 0:
					SetCursorPosition(67, 4);
					cout << "                        ";
					SetCursorPosition(67, 4);
					cout << equipment.GetHelmet().GetName();
					SetCursorPosition(67, 6);
					cout << "                        ";
					SetCursorPosition(67, 6);
					cout << "Count: " << equipment.GetHelmet().GetCount();
					SetCursorPosition(67, 8);
					cout << "                        ";
					SetCursorPosition(67, 8);
					cout << equipment.GetHelmet().GetType();
					SetCursorPosition(67, 10);


					ForNumb = 10;
					for (int i = 0; i < 150; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << " ";
					}

					ForNumb = 10;
					for (int i = 0; equipment.GetHelmet().GetDescription()[i] != '\0'; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << equipment.GetHelmet().GetDescription()[i];
					}
					break;
				case 1:
					SetCursorPosition(67, 4);
					cout << "                        ";
					SetCursorPosition(67, 4);
					cout << equipment.GetCuirass().GetName();
					SetCursorPosition(67, 6);
					cout << "                        ";
					SetCursorPosition(67, 6);
					cout << "Count: " << equipment.GetCuirass().GetCount();
					SetCursorPosition(67, 8);
					cout << "                        ";
					SetCursorPosition(67, 8);
					cout << equipment.GetCuirass().GetType();
					SetCursorPosition(67, 10);


					ForNumb = 10;
					for (int i = 0; i < 150; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << " ";
					}

					ForNumb = 10;
					for (int i = 0; equipment.GetCuirass().GetDescription()[i] != '\0'; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << equipment.GetCuirass().GetDescription()[i];
					}
					break;
				case 2:
					SetCursorPosition(67, 4);
					cout << "                        ";
					SetCursorPosition(67, 4);
					cout << equipment.GetLeggins().GetName();
					SetCursorPosition(67, 6);
					cout << "                        ";
					SetCursorPosition(67, 6);
					cout << "Count: " << equipment.GetLeggins().GetCount();
					SetCursorPosition(67, 8);
					cout << "                        ";
					SetCursorPosition(67, 8);
					cout << equipment.GetLeggins().GetType();
					SetCursorPosition(67, 10);


					ForNumb = 10;
					for (int i = 0; i < 150; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << " ";
					}

					ForNumb = 10;
					for (int i = 0; equipment.GetLeggins().GetDescription()[i] != '\0'; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << equipment.GetLeggins().GetDescription()[i];
					}
					break;
				case 3:
					SetCursorPosition(67, 4);
					cout << "                        ";
					SetCursorPosition(67, 4);
					cout << equipment.GetBoots().GetName();
					SetCursorPosition(67, 6);
					cout << "                        ";
					SetCursorPosition(67, 6);
					cout << "Count: " << equipment.GetBoots().GetCount();
					SetCursorPosition(67, 8);
					cout << "                        ";
					SetCursorPosition(67, 8);
					cout << equipment.GetBoots().GetType();
					SetCursorPosition(67, 10);


					ForNumb = 10;
					for (int i = 0; i < 150; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << " ";
					}

					ForNumb = 10;
					for (int i = 0; equipment.GetBoots().GetDescription()[i] != '\0'; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << equipment.GetBoots().GetDescription()[i];
					}
					break;
				case 4:
					SetCursorPosition(67, 4);
					cout << "                        ";
					SetCursorPosition(67, 4);
					cout << equipment.GetWeapon().GetName();
					SetCursorPosition(67, 6);
					cout << "                        ";
					SetCursorPosition(67, 6);
					cout << "Count: " << equipment.GetWeapon().GetCount();
					SetCursorPosition(67, 8);
					cout << "                        ";
					SetCursorPosition(67, 8);
					cout << equipment.GetWeapon().GetType();
					SetCursorPosition(67, 10);


					ForNumb = 10;
					for (int i = 0; i < 150; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << " ";
					}

					ForNumb = 10;
					for (int i = 0; equipment.GetWeapon().GetDescription()[i] != '\0'; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << equipment.GetWeapon().GetDescription()[i];
					}
					break;
				case 5:
					SetCursorPosition(67, 4);
					cout << "                        ";
					SetCursorPosition(67, 4);
					cout << equipment.GetShield().GetName();
					SetCursorPosition(67, 6);
					cout << "                        ";
					SetCursorPosition(67, 6);
					cout << "Count: " << equipment.GetShield().GetCount();
					SetCursorPosition(67, 8);
					cout << "                        ";
					SetCursorPosition(67, 8);
					cout << equipment.GetShield().GetType();
					SetCursorPosition(67, 10);


					ForNumb = 10;
					for (int i = 0; i < 150; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << " ";
					}

					ForNumb = 10;
					for (int i = 0; equipment.GetShield().GetDescription()[i] != '\0'; i++)
					{
						if (i % 24 == 0)
						{
							SetCursorPosition(67, ForNumb);
							ForNumb++;
						}
						cout << equipment.GetShield().GetDescription()[i];
					}
					break;
				}
			}
		}
		//end

		//key scenery
		//hide wall of code
		if (true)
		{
			SetCursorPosition(7, 24);

			int key = _getch();

			switch (key)
			{
			case UP:
				if (activeTableItem == 1)
				{
					menuItemsCount = inventory.GetSize();
					lastMenuItem = menuItemsCount - 1;
				}

				if (activeMenuItem > 0)
				{
					activeMenuItem -= 1;
				}
				else
				{
					activeMenuItem = lastMenuItem;
				}

				break;
			case DOWN:
				if (activeTableItem == 1)
				{
					menuItemsCount = inventory.GetSize();
					lastMenuItem = menuItemsCount - 1;
				}

				if (activeMenuItem < lastMenuItem)
				{
					activeMenuItem += 1;
				}
				else
				{
					activeMenuItem = 0;
				}

				break;
			case LEFT:
				if (activeTableItem == 1)
				{
					activeTableItem = 0;
					activeMenuItem = 0;
					menuItemsCount = 6; //helmet + cuirass + leggins + boots + weapon + shield
					lastMenuItem = menuItemsCount - 1;
				}
				else
				{
					activeTableItem = 1;
					activeMenuItem = 0;
					menuItemsCount = inventory.GetSize();
					lastMenuItem = menuItemsCount - 1;
				}
				break;
			case RIGHT:
				if (activeTableItem == 1)
				{
					activeTableItem = 0;
					activeMenuItem = 0;
					menuItemsCount = 6; //helmet + cuirass + leggins + boots + weapon + shield
					lastMenuItem = menuItemsCount - 1;
				}
				else
				{
					activeTableItem = 1;
					activeMenuItem = 0;
					menuItemsCount = inventory.GetSize();
					lastMenuItem = menuItemsCount - 1;
				}
				break;
			case ENTER:
				if (activeTableItem == 1 && inventory.GetSize() != 0)
				{
					switch (inventory.GetInventory()[activeMenuItem].GetType()[0])
					{
					case 'H':
						if (strcmp(equipment.GetHelmet().GetName(), "None") == 0)
						{
							equipment.SetHelmet(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						else
						{
							inventory.AddItem(equipment.GetHelmet());
							equipment.SetHelmet(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						break;
					case 'C':
						if (strcmp(equipment.GetCuirass().GetName(), "None") == 0)
						{
							equipment.SetCuirass(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						else
						{
							inventory.AddItem(equipment.GetCuirass());
							equipment.SetCuirass(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						break;
					case 'L':
						if (strcmp(equipment.GetLeggins().GetName(), "None") == 0)
						{
							equipment.SetLeggins(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						else
						{
							inventory.AddItem(equipment.GetLeggins());
							equipment.SetLeggins(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						break;
					case 'B':
						if (strcmp(equipment.GetBoots().GetName(), "None") == 0)
						{
							equipment.SetBoots(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						else
						{
							inventory.AddItem(equipment.GetBoots());
							equipment.SetBoots(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						break;
					case 'W':
						if (strcmp(equipment.GetWeapon().GetName(), "None") == 0)
						{
							equipment.SetWeapon(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						else
						{
							inventory.AddItem(equipment.GetWeapon());
							equipment.SetWeapon(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						break;
					case 'S':
						if (strcmp(equipment.GetShield().GetName(), "None") == 0)
						{
							equipment.SetShield(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						else
						{
							inventory.AddItem(equipment.GetShield());
							equipment.SetShield(inventory.GetInventory()[activeMenuItem]);
							inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						}
						break;
					case 'U':
						inventory.RemoveItem(inventory.GetInventory()[activeMenuItem]);
						if (GetHealth() < 100 && GetHealth() > 50)
						{
							SetHealth(100);
						}
						else if (GetHealth() < 50)
						{
							SetHealth(GetHealth() + 50);
							if (GetHealth() > 100)
							{
								SetHealth(100);
							}
						}
						break;
					}
					if (activeMenuItem == lastMenuItem && activeMenuItem != 0)
					{
						menuItemsCount--;
						lastMenuItem = menuItemsCount - 1;
						activeMenuItem = lastMenuItem;
					}
				}
				else if (activeTableItem == 0)
				{
					switch (activeMenuItem)
					{
					case 0:
						if (strcmp(equipment.GetHelmet().GetName(), "None") != 0)
						{
							inventory.AddItem(equipment.GetHelmet());
							equipment.SetHelmet("None", "Helmet", 1, " ");
						}
						break;
					case 1:
						if (strcmp(equipment.GetCuirass().GetName(), "None") != 0)
						{
							inventory.AddItem(equipment.GetCuirass());
							equipment.SetCuirass("None", "Cuirass", 1, " ");
						}
						break;
					case 2:
						if (strcmp(equipment.GetLeggins().GetName(), "None") != 0)
						{
							inventory.AddItem(equipment.GetLeggins());
							equipment.SetLeggins("None", "Leggins", 1, " ");
						}
						break;
					case 3:
						if (strcmp(equipment.GetBoots().GetName(), "None") != 0)
						{
							inventory.AddItem(equipment.GetBoots());
							equipment.SetBoots("None", "Boots", 1, " ");
						}
						break;
					case 4:
						if (strcmp(equipment.GetWeapon().GetName(), "None") != 0)
						{
							inventory.AddItem(equipment.GetWeapon());
							equipment.SetWeapon("None", "Weapon", 1, " ");
						}
						break;
					case 5:
						if (strcmp(equipment.GetShield().GetName(), "None") != 0)
						{
							inventory.AddItem(equipment.GetShield());
							equipment.SetShield("None", "Shield", 1, " ");
							break;
						}
					}
				}

				break;
			case TAB:
				SetCursorPosition(0, 0);
				map->Print(player->GetPosition());
				SetCursorPosition(0, 28);
				cout << "                                                                                                            " << endl;
				active = false;
				break;
			case ESCAPE:
				SetCursorPosition(0, 0);
				map->Print(player->GetPosition());
				SetCursorPosition(0, 28);
				cout << "                                                                                                            " << endl;
				active = false;
				break;
			}
		}
		//end
	}
}

void CGame::Menu()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	int activeMenuItem = 0;
	const int menuItemCount = 4;
	int lastMenuItem = menuItemCount - 1;
	char* menuItemList[menuItemCount] = { "New Game", "Continue", "Save Game", "Exit" };

	enum { UP = 72, DOWN = 80, ENTER = 13, ESCAPE = 27,};

	char DeathSpeakers[112] = { 203, 187, 32, 201, 205, 32, 201, 187, 32, 203, 32, 186, 186, 32, 201, 187, 32, 201, 187, 32, 201, 205, 32, 201, 187, 32, 186, 201, 32, 201, 205, 32, 201, 187, 32, 201, 187,
								186, 186, 32, 186, 205, 32, 204, 185, 32, 186, 32, 204, 185, 32, 200, 187, 32, 186, 186, 32, 186, 205, 32, 204, 185, 32, 204, 185, 32, 186, 205, 32, 204, 188, 32, 200, 187,
								202, 188, 32, 200, 205, 32, 186, 186, 32, 186, 32, 186, 186, 32, 200, 188, 32, 204, 188, 32, 200, 205, 32, 186, 186, 32, 186, 200, 32, 200, 205, 32, 204, 187, 32, 200, 188 };

	int xCoord = 4;
	SetCursorPosition(37, xCoord);
	for (int i = 0; i < 112; i++)
	{
		if (i % 37 == 0)
		{
			SetCursorPosition(37, xCoord++);
		}
		cout << DeathSpeakers[i];
	}
	cout << endl;

	SetCursorPosition(42, 27);
	cout << "Project by Vitaliy Besarab";

	while (MenuActive)
	{		
		for (int i = 0; i < menuItemCount; i++)
		{
			SetCursorPosition(50, 13 + i);

			if (activeMenuItem == i)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			}
			cout << menuItemList[i] << endl;
			SetConsoleTextAttribute(hConsole, csbi.wAttributes);
		}

		int key = _getch();
		switch (key)
		{
		case UP:
			if (activeMenuItem > 0)
			{
				activeMenuItem -= 1;
			}
			else
			{
				activeMenuItem = lastMenuItem;
			}

			break;
		case DOWN:
			if (activeMenuItem < lastMenuItem)
			{
				activeMenuItem += 1;
			}
			else
			{
				activeMenuItem = 0;
			}

			break;
		case ENTER:
			switch (activeMenuItem)
			{
			case 0:
				map = new CMap("maps/map_3.txt");
				player = new CPlayer(map->GetPlayerBasePosition());
				location = 1;
				inventory.SetSize(0);
				equipment.SetBoots("None", "Boots", 1, " ");
				equipment.SetCuirass("None", "Cuirass", 1, " ");
				equipment.SetLeggins("None", "Leggins", 1, " ");
				equipment.SetHelmet("None", "Helmet", 1, " ");
				equipment.SetWeapon("None", "Weapon", 1, " ");
				equipment.SetShield("None", "Shield", 1, " ");
				health = 100;
				stats.SetDexterity(5);
				stats.SetIntelegence(5);
				stats.SetStrength(5);
				PlayGame();
				break;
			case 1:
				if (gameStartActive)
				{
					PlayGame();
				}
				else
				{
					SetCursorPosition(46, 25);
					cout << "No game to continue";
					system("pause >> NULL");
					SetCursorPosition(46, 25);
					cout << "                   ";
				}
				break;
			case 2:
				if (gameStartActive)
				{
					SetCursorPosition(51, 25);
					cout << "Saved";
					system("pause >> NULL");
					SetCursorPosition(51, 25);
					cout << "     ";
				}
				else
				{
					SetCursorPosition(47, 25);
					cout << "No game to save";
					system("pause >> NULL");
					SetCursorPosition(47, 25);
					cout << "               ";
				}				
				break;
			case 3:
				MenuActive = false;
				gameStartActive = false;
				break;
			}
			break;
		case ESCAPE:
			if (gameStartActive)
			{
				PlayGame();
			}
			break;
		}
	}
}

void CGame::Battle()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	if (GetHealth() == 10)
	{
		SetCursorPosition(51, 28);
		cout << "You died" << endl;
		SetHealth(100);
		system("pause >> NULL");
		SetCursorPosition(0, 28);
		cout << "                                                                                                       " << endl;
		SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
		player->Despawn();
		player = new CPlayer(map->GetPlayerBasePosition());
		player->Spawn();
		SetConsoleTextAttribute(hConsole, csbi.wAttributes);
	}
	else
	{
		SetCursorPosition(44, 28);
		cout << "Suffered 10 dmg";
		int RandNum = rand() % 16;
		if (RandNum == 5)
		{
			stats.IncreaseStr();
			cout << " (Strength up)" << endl;
		}
		SetHealth(GetHealth() - 10);
		system("pause >> NULL");
		SetCursorPosition(0, 28);
		cout << "                                                                                                       " << endl;
	}
}

void CGame::Dialog()
{
	SetCursorPosition(44, 28);
	cout << "Go on. There is nothing to say.";
	int RandNum = rand() % 16;
	if (RandNum == 5)
	{
		stats.IncreaseInt();
		cout << " (Intelegence up)" << endl;
	}
	system("pause >> NULL");
	SetCursorPosition(0, 28);
	cout << "                                                                                                           " << endl;
}

void CGame::PlayGame()
{
	gameStartActive = true;
	srand((unsigned)time(0));

	enum { PATH = 0, WALL = 1, PLAYER = 2, DOOR = 3, ENEMY = 4, CHEST = 5, GUARD_NPC = 6 };
	enum { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, TAB = 9, ESCAPE = 27 };
	bool game = true;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	int itemsSize;
	CItem** items;
	Load("items.txt", items, itemsSize);

	SetCursorPosition(0, 0);
	map->Print(player->GetPosition());
	SetCursorPosition(0, 28);
	cout << "                                                                                                            " << endl;

	while (game)
	{
		int key = _getch();

		switch (key)
		{
		case UP:
			if (map->GetTargetObj(player->GetOneStepUp()) == PATH)
			{
				if (location == 1)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				else if (location == 2)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				player->Despawn();
				player->MoveUp();
				player->Spawn();
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
			else if (map->GetTargetObj(player->GetOneStepUp()) == DOOR)
			{
				NewLocation();
			}
			else if (map->GetTargetObj(player->GetOneStepUp()) == ENEMY)
			{
				Battle();
			}
			else if (map->GetTargetObj(player->GetOneStepUp()) == CHEST)
			{
				RandChestItem(items);
				system("pause >> NULL");
				SetCursorPosition(0, 28);
				cout << "                                                                                                 " << endl;
			}
			else if (map->GetTargetObj(player->GetOneStepUp()) == GUARD_NPC)
			{
				Dialog();
			}
			break;

		case DOWN:
			if (map->GetTargetObj(player->GetOneStepDown()) == PATH)
			{
				if (location == 1)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				else if (location == 2)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				player->Despawn();
				player->MoveDown();
				player->Spawn();
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
			else if (map->GetTargetObj(player->GetOneStepDown()) == DOOR)
			{
				NewLocation();
			}
			else if (map->GetTargetObj(player->GetOneStepDown()) == ENEMY)
			{
				Battle();
			}
			else if (map->GetTargetObj(player->GetOneStepDown()) == CHEST)
			{
				RandChestItem(items);
				system("pause >> NULL");
				SetCursorPosition(0, 28);
				cout << "                                                                                                            " << endl;
			}
			else if (map->GetTargetObj(player->GetOneStepDown()) == GUARD_NPC)
			{
				Dialog();
			}
			break;

		case LEFT:
			if (map->GetTargetObj(player->GetOneStepLeft()) == PATH)
			{
				if (location == 1)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				else if (location == 2)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				player->Despawn();
				player->MoveLeft();
				player->Spawn();
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
			else if (map->GetTargetObj(player->GetOneStepLeft()) == DOOR)
			{
				NewLocation();
			}
			else if (map->GetTargetObj(player->GetOneStepLeft()) == ENEMY)
			{
				Battle();
			}
			else if (map->GetTargetObj(player->GetOneStepLeft()) == CHEST)
			{
				RandChestItem(items);
				system("pause >> NULL");
				SetCursorPosition(0, 28);
				cout << "                                                                                                            " << endl;
			}
			else if (map->GetTargetObj(player->GetOneStepLeft()) == GUARD_NPC)
			{
				Dialog();
			}
			break;

		case RIGHT:
			if (map->GetTargetObj(player->GetOneStepRight()) == PATH)
			{
				if (location == 1)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				else if (location == 2)
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				}
				player->Despawn();
				player->MoveRight();
				player->Spawn();
				SetConsoleTextAttribute(hConsole, csbi.wAttributes);
			}
			else if (map->GetTargetObj(player->GetOneStepRight()) == DOOR)
			{
				NewLocation();
			}
			else if (map->GetTargetObj(player->GetOneStepRight()) == ENEMY)
			{
				Battle();
			}
			else if (map->GetTargetObj(player->GetOneStepRight()) == CHEST)
			{
				RandChestItem(items);
				system("pause >> NULL");
				SetCursorPosition(0, 28);
				cout << "                                                                                                            " << endl;
			}
			else if (map->GetTargetObj(player->GetOneStepRight()) == GUARD_NPC)
			{
				Dialog();
			}
			break;
		case TAB:
			PrintEquipmentInventory();
			break;
		case ESCAPE:
			system("cls");
			Menu();
			if (MenuActive == false)
			{
				game = false;
			}
			break;
		}

	}
}

void CGame::RandChestItem(CItem** items)
{
	int randnum = rand() % 11;

	SetCursorPosition(44, 28);
	cout << "You have found ";

	switch (randnum)
	{
	case 0:
		cout << items[0]->GetName();
		inventory.AddItem(items[0]);
		break;
	case 1:
		cout << items[1]->GetName();
		inventory.AddItem(items[1]);
		break;
	case 2:
		cout << items[2]->GetName();
		inventory.AddItem(items[2]);
		break;
	case 3:
		cout << items[3]->GetName();
		inventory.AddItem(items[3]);
		break;
	case 4:
		cout << items[4]->GetName();
		inventory.AddItem(items[4]);
		break;
	case 5:
		cout << items[5]->GetName();
		inventory.AddItem(items[5]);
		break;
	case 6:
		cout << items[6]->GetName();
		inventory.AddItem(items[6]);
		break;
	case 7:
		cout << items[7]->GetName();
		inventory.AddItem(items[7]);
		break;
	case 8:
		cout << items[8]->GetName();
		inventory.AddItem(items[8]);
		break;
	case 9:
		cout << items[9]->GetName();
		inventory.AddItem(items[9]);
		break;
	case 10:
		cout << "nothing!";
		break;
	}

	int RandNum = rand() % 16;
	if (RandNum == 5)
	{
		stats.IncreaseDex();
		cout << " (Dexterity up)" << endl;
	}
}

void CGame::NewLocation()
{
	if (location == 1)
	{
		if (map != nullptr)
		{
			delete map;
		}

		map = new CMap("maps/map_2.txt");
		player = new CPlayer(map->GetPlayerBasePosition());
		SetCursorPosition(0, 0);
		map->Print(player->GetPosition());
		SetCursorPosition(0, 28);
		cout << "                                                                                                            " << endl;
		location = 2;
	}
	else if (location == 2)
	{
		if (map != nullptr)
		{
			delete map;
		}

		map = new CMap("maps/map_1.txt");
		player = new CPlayer(map->GetPlayerBasePosition());
		SetCursorPosition(0, 0);
		map->Print(player->GetPosition());
		SetCursorPosition(0, 28);
		cout << "                                                                                                            " << endl;
		location = 1;
	}
}

int CGame::GetHealth()
{
	return health;
}

void CGame::SetHealth(int _health)
{
	health = _health;
}

CGame::~CGame()
{
	delete map;
	delete player;
}