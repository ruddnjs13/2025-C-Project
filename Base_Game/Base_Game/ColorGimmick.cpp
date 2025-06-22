#include "ColorGimmick.h"

void ColorGimmick::Init()
{
	slotIdx = 0;
	for (int i = 0; i < 5; i++) {
		submitArr[i] = COLOR::GRAY;
		colorGimickTile[i] = '0';
	}
}

void ColorGimmick::Interact(char btnType)
{
	if (slotIdx > 4) return;
	switch (btnType)
	{
	case '2':
		submitArr[slotIdx] = COLOR::RED;
		colorGimickTile[slotIdx] = '2';
		slotIdx++;
		break;
	case '3':
		submitArr[slotIdx] = COLOR::GREEN;
		colorGimickTile[slotIdx] = '3';
		slotIdx++;
		break;
	case '4':
		submitArr[slotIdx] = COLOR::BLUE;
		colorGimickTile[slotIdx] = '4';
		slotIdx++;
		break;
	case '5':
		submitArr[slotIdx] = COLOR::YELLOW;
		colorGimickTile[slotIdx] = '5';
		slotIdx++;
		break;
	case '6':
		submitArr[slotIdx] = COLOR::WHITE;
		colorGimickTile[slotIdx] = '6';
		slotIdx++;
		break;
	case '7':
		submitArr[slotIdx] = COLOR::GRAY;;
		colorGimickTile[slotIdx] = '7';
		slotIdx++;
		break;
	case '8':
		submitArr[slotIdx] = COLOR::MINT;;
		colorGimickTile[slotIdx] = '8';
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
