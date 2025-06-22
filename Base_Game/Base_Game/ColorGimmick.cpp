#include "ColorGimmick.h"

void ColorGimmick::Init()
{
	slotIdx = 0;
	for (int i = 0; i < 5; i++) {
		submitArr[i] = COLOR::GRAY;
	}
}

void ColorGimmick::Interact(char btnType)
{
	switch (btnType)
	{
	case '2':
		submitArr[slotIdx] = COLOR::RED;
		colorGimickTile[slotIdx] = (char)ColorGimickTile::Red;
		slotIdx++;
		break;
	case '3':
		submitArr[slotIdx] = COLOR::GREEN;
		colorGimickTile[slotIdx] =(char) ColorGimickTile::Green;
		slotIdx++;
		break;
	case '4':
		submitArr[slotIdx] = COLOR::BLUE;
		colorGimickTile[slotIdx] = (char)ColorGimickTile::Blue;
		slotIdx++;
		break;
	case '5':
		submitArr[slotIdx] = COLOR::YELLOW;
		colorGimickTile[slotIdx] = (char)ColorGimickTile::Yellow;
		slotIdx++;
		break;
	case '6':
		submitArr[slotIdx] = COLOR::WHITE;
		colorGimickTile[slotIdx] = (char)ColorGimickTile::White;
		slotIdx++;
		break;
	case '7':
		submitArr[slotIdx] = COLOR::GRAY;;
		colorGimickTile[slotIdx] = (char)ColorGimickTile::Gray;
		slotIdx++;
		break;
	case '8':
		submitArr[slotIdx] = COLOR::MINT;;
		colorGimickTile[slotIdx] = (char)ColorGimickTile::Mint;
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
			SetColor(ColorSetArr[i], COLOR::BLACK);
  		    Gotoxy(start_x + (Color_WIDTH * i), start_y + j);
			cout << "¡á¡á¡á¡á¡á¡á" << "\n";

		}
		SetColor(COLOR::WHITE, COLOR::BLACK);
	}
}

void ColorGimmick::Submit()
{
}
