#pragma once
enum class Key
{
	// W키: 슬라임 ONOFF, E키: PUSH ONOFF
	UP, DOWN, LEFT, RIGHT, W, E, SPACE, ESC, FAIL
};
enum class Menu
{
	START, INFO, QUIT, FAIL
};

enum class Scene
{
	TITLE, GAME, INFO, QUIT, END
};

enum class Tile
{
	WALL = '0', ROAD = '1', START, GOAL
};

enum class GimickTile
{
	A= 65, Z = 90, ENTER = 93
};