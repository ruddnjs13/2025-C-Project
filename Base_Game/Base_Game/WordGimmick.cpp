#include "WordGimmick.h"

void WordGimmick::Init()
{
   
}

void WordGimmick::Interact(char btnType)
{
    if (slotIdx > 4) return;

    submitArr[slotIdx++] = btnType;
}

void WordGimmick::GimmickRender()
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < WORD_HEIGHT; ++j)
		{
			Gotoxy(start_x + (WORD_WIDTH * i), start_y + j);
			wcout << asciiMap[submitArr[i]][j] << '\n';
		}
    }
}

void WordGimmick::Submit()
{
}
