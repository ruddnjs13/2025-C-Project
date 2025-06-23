#include "WordGimmick.h"

void WordGimmick::Init()
{
	slotIdx = 0;
	for (int i = 0; i < 5; i++)
	{
		submitArr[i] = 'A';
	}
}

void WordGimmick::Interact(char btnType)
{
    if (slotIdx > 4) return;

    submitArr[slotIdx++] = btnType;
	system("cls");
}

void WordGimmick::GimmickRender()
{
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < WORD_HEIGHT; ++j)
		{
			Gotoxy(start_x + (WORD_WIDTH * i), start_y + j);
			wcout << asciiAlphabets.asciiMap[submitArr[i]][j] << '\r' << '\n';
		}
	}

	int wcoutmode = _setmode(_fileno(stdout), coutmode);
}


