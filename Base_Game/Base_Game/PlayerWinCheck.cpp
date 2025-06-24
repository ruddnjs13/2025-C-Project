#include "PlayerWinCheck.h"



void PlayerWinCheck::PlayerWinCheckScene(int player1Win, int Player2Win)
{
	PlayerWinChecker(player1Win, Player2Win);
	PlayerWinCheckRender();
	Sleep(3000);
	SceneManager::GetInstance()->currentScene = Scene::GAME;
	SceneManager::GetInstance()->EnterAnimation();
}

void PlayerWinCheck::PlayerWinChecker(int player1Win, int Player2Win)
{
	this->player1Win = player1Win;
	this->player2Win = Player2Win;
	if (player1Win >= 2) 
	{
		isPlayer1Win = true;
	}
	if (Player2Win>=2)
	{
		isPlayer2Win = true;
	}
}

void PlayerWinCheck::PlayerWinCheckRender()
{
	if (!isPlayer1Win && !isPlayer2Win) 
	{
		Gotoxy(GetConsoleResolution().X / 2, GetConsoleResolution().Y / 2);
		cout << "Player 1 Win : " << player1Win << endl;
		Gotoxy(GetConsoleResolution().X/2, GetConsoleResolution().Y / 2+1);
		cout << "Player 2 Win : " << player2Win << endl;
	}
	else
	{
		if (isPlayer1Win)
		{
			Gotoxy(GetConsoleResolution().X / 2, GetConsoleResolution().Y / 2);
			cout << "Player 1 Win!" << endl;
		}
		else
		{
			Gotoxy(GetConsoleResolution().X / 2, GetConsoleResolution().Y / 2);
			cout << "Player 2 Win!" << endl;
		}
	}
}
