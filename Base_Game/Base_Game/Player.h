#pragma once
typedef struct _pos
{
	int x;
	int y;
	bool operator == (const _pos& other) const
	{
		return (x == other.x && y == other.y);
	}
}POS, * PPOS;

// ��ġ ���� ����ü
typedef struct _tagplayerpos
{
	POS tPos;// ���� ��ġ
	POS tNewPos;// ���� ��ġ
	POS tStartPos; // ���� ��ġ
	POS tEndPos;   // ��ǥ ��ġ
} PLAYERPOS, * PPLAYERPOS;

typedef struct _tagplayer
{
	PLAYERPOS position;    // ��ġ ����
} PLAYER, * PPLAYER;


void PlayerRender(char player,PPLAYER pPlayer);