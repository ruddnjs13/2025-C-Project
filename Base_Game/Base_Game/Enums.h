#pragma once
enum class Key
{
	// WŰ: ������ ONOFF, EŰ: PUSH ONOFF
	UP, DOWN, LEFT, RIGHT, W, E, SPACE, ESC, FAIL
};
enum class Menu
{
	START, INFO, QUIT, FAIL
};

enum class Scene
{
	TITLE,STAGESLECT,WINCHECK, GAME, INFO, QUIT, END
};

enum class Tile
{
	WALL = '0', ROAD, SHOOT = '9'
};

enum class ColorGimickTile
{
	Red = '2', Green, Blue, Yellow, White, Mint,
	ENTER = 93
};

enum class GimickTile
{
	A= 65, Z = 90, ENTER = 93
};

enum class GimmickMode
{
	CORLOR=0,WORD=1,SHOOT=2
};

