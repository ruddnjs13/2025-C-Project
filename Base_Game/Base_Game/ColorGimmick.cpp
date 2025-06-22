#include "ColorGimmick.h"

void ColorGimmick::Init()
{
	slotIdx = 0;
	for (int i = 0; i < 5; i++) {
		submitArr[i] = COLOR::GRAY;
		ColorSetArr[i] = COLOR::GRAY;
	}
}

void ColorGimmick::Interact(char btnType)
{
	switch (btnType)
	{
	case '2':
		ColorSetArr[slotIdx] = COLOR::RED;
		submitArr[slotIdx] = ColorGimickTile::Red;
		slotIdx++;
		break;
	case '3':
		ColorSetArr[slotIdx] = COLOR::GREEN;
		submitArr[slotIdx] = ColorGimickTile::Green;
		slotIdx++;
		break;
	case '4':
		ColorSetArr[slotIdx] = COLOR::BLUE;
		submitArr[slotIdx] = ColorGimickTile::Blue;
		slotIdx++;
		break;
	case '5':
		ColorSetArr[slotIdx] = COLOR::YELLOW;
		submitArr[slotIdx] = ColorGimickTile::Yellow;
		slotIdx++;
		break;
	case '6':
		ColorSetArr[slotIdx] = COLOR::WHITE;
		submitArr[slotIdx] = ColorGimickTile::White;
		slotIdx++;
		break;
	case '7':
		ColorSetArr[slotIdx] = COLOR::GRAY;;
		submitArr[slotIdx] = ColorGimickTile::Gray;
		slotIdx++;
		break;
	case '8':
		ColorSetArr[slotIdx] = COLOR::MINT;;
		submitArr[slotIdx] = ColorGimickTile::Mint;
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
			cout << "�������" << "\n";

		}
		SetColor(COLOR::WHITE, COLOR::BLACK);
	}
}

void ColorGimmick::Submit()
{
}
