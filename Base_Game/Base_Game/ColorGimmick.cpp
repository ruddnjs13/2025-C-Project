#include "ColorGimmick.h"

void ColorGimmick::Init()
{
}

void ColorGimmick::Interact(char btnType)
{
	switch (btnType)
	{
	case '2':
		SetColor(COLOR::RED);
		break;
	case '3':
		SetColor(COLOR::GREEN);
		break;
	case '4':
		SetColor(COLOR::BLUE);
		break;
	case '5':
		SetColor(COLOR::YELLOW);
		break;
	case '6':
		SetColor(COLOR::WHITE);
		break;
	case '7':
		SetColor(COLOR::GRAY);
		break;
	case '8':
		SetColor(COLOR::MINT);
		break;
	default:
		SetColor(COLOR::WHITE);
		break;
	}
}

void ColorGimmick::GimmickRender()
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < Color_HEIGHT; ++j)
		{

			Gotoxy(start_x + (Color_WIDTH * i), start_y + j);
			cout << "бс" << '\n';

		}
	}
}
