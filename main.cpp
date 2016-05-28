#include "CGame.h"

void main()
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	SetConsoleTitle(L"Deathspeakers");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);


	// set font and font size
	CONSOLE_FONT_INFOEX ConsoleFont = { 0 };
	GetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);

	wcscpy_s(ConsoleFont.FaceName, 13, L"Raster Fonts");
	SetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);

	ConsoleFont.FontWeight = sizeof(CONSOLE_FONT_INFOEX);
	ConsoleFont.dwFontSize.X = 8;
	ConsoleFont.dwFontSize.Y = 9;
	SetCurrentConsoleFontEx(hConsole, FALSE, &ConsoleFont);
	//end

	// set console size and buffer
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	// scrn = { 150, 50 };
	scrn.X = 110;
	scrn.Y = 30;
	SMALL_RECT src = { 0, 0, scrn.X - 1, scrn.Y - 1 };

	SetConsoleScreenBufferSize(hConsole, scrn);
	SetConsoleWindowInfo(hConsole, TRUE, &src);
	//end

	// hide cursor
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cci);
	//end

	// console position
	SetWindowPos(FindWindow(NULL, L"Deathspeakers"), HWND_TOPMOST, 30, 30, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	//end

	CGame *game = new CGame();
	delete game;
}
