#include "ColorGimmick.h"

void ColorGimmick::Init()
{
	slotIdx = 0;
}

void ColorGimmick::Interact(char btnType)
{
	switch (btnType)
	{
	case '2':
		color[slotIdx] = COLOR::RED;
		slotIdx++;
		break;
	case '3':
		color[slotIdx] = COLOR::GREEN;
		slotIdx++;
		break;
	case '4':
		color[slotIdx] = COLOR::BLUE;
		slotIdx++;
		break;
	case '5':
		color[slotIdx] = COLOR::YELLOW;
		slotIdx++;
		break;
	case '6':
		color[slotIdx] = COLOR::WHITE;
		slotIdx++;
		break;
	case '7':
		color[slotIdx] = COLOR::GRAY;;
		slotIdx++;
		break;
	case '8':
		color[slotIdx] = COLOR::MINT;;
		slotIdx++;
		break;
	}
	
}

void ColorGimmick::GimmickRender()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < Color_HEIGHT; ++j)
		{
			SetColor(color[i], COLOR::BLACK);
  		    Gotoxy(start_x + (Color_WIDTH * i), start_y + j);
			cout << "¡á¡á¡á¡á¡á¡á" << "\n";

		}
		SetColor(COLOR::WHITE, COLOR::BLACK);
	}
}

void ColorGimmick::Submit()
{
}
