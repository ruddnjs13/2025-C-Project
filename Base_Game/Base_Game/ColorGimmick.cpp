#include "ColorGimmick.h"

void ColorGimmick::Init()
{
}

void ColorGimmick::Interact(char btnType)
{
	switch (btnType)
	{

	}
}

void ColorGimmick::GimmickRender()
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < WORD_HEIGHT; ++j)
		{

			Gotoxy(start_x + (WORD_WIDTH * i), start_y + j);
			cout << "бс" << '\n';

		}
	}
}
