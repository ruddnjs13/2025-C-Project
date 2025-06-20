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
		submitArr[slotIdx] = COLOR::RED;
		slotIdx++;
		break;
	case '3':
		submitArr[slotIdx] = COLOR::GREEN;
		slotIdx++;
		break;
	case '4':
		submitArr[slotIdx] = COLOR::BLUE;
		slotIdx++;
		break;
	case '5':
		submitArr[slotIdx] = COLOR::YELLOW;
		slotIdx++;
		break;
	case '6':
		submitArr[slotIdx] = COLOR::WHITE;
		slotIdx++;
		break;
	case '7':
		submitArr[slotIdx] = COLOR::GRAY;;
		slotIdx++;
		break;
	case '8':
		submitArr[slotIdx] = COLOR::MINT;;
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
			SetColor(submitArr[i], COLOR::BLACK);
  		    Gotoxy(start_x + (Color_WIDTH * i), start_y + j);
			cout << "¡á¡á¡á¡á¡á¡á" << "\n";

		}
		SetColor(COLOR::WHITE, COLOR::BLACK);
	}
}

void ColorGimmick::Submit()
{
}
