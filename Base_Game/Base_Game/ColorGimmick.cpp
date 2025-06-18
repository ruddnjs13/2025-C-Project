#include "ColorGimmick.h"

void ColorGimmick::Interact(char btnType)
{
	color[colorIndex] = btnType;
	colorIndex++;
}

void ColorGimmick::GimmickRender()
{
	for (int i = 0; i < colorIndex; ++i)
	{
		switch (color[colorIndex])
		{
		case '2':
			SetColor(COLOR::RED);
			colorGimickTile[i] = ColorGimickTile::Red;
			cout << "��";
			break;
		case '3':
			SetColor(COLOR::GREEN);
			colorGimickTile[i] = ColorGimickTile::Green;
			cout << "��";
			break;
		case '4':
			SetColor(COLOR::BLUE);
			colorGimickTile[i] = ColorGimickTile::Blue;
			cout << "��";
			break;
		case '5':
			SetColor(COLOR::YELLOW);
			colorGimickTile[i] = ColorGimickTile::Yellow;
			cout << "��";
			break;
		case '6':
			SetColor(COLOR::WHITE);
			colorGimickTile[i] = ColorGimickTile::White;
			cout << "��";
			break;
		case '7':
			SetColor(COLOR::GRAY);
			colorGimickTile[i] = ColorGimickTile::Gray;
			cout << "��";
			break;
		case '8':
			SetColor(COLOR::MINT);
			colorGimickTile[i] = ColorGimickTile::Mint;
			cout << "��";
			break;
		default:
			SetColor(COLOR::WHITE);
			break;
		}
	}
}
