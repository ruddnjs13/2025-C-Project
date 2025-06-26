#include "PlayerWinCheck.h"



PlayerWinCheck::PlayerWinCheck()
{
	PlayerWinCheckAscii();
	PlayerWinInit();
}

void PlayerWinCheck::PlayerWinInit()
{
	player1Win = 0;
	player2Win = 0;
	isPlayer1Win = false;
	isPlayer2Win = false;
}

void PlayerWinCheck::PlayerWinCheckScene(int player1Win, int Player2Win)
{
	PlayerWinChecker(player1Win, Player2Win);
	PlayerWinCheckRender();
	Sleep(3000);
	if (isPlayer1Win == false || isPlayer2Win == false) {

		SceneManager::GetInstance()->currentScene = Scene::GAME;
		SceneManager::GetInstance()->EnterAnimation();
	}
	else
	{
		SceneManager::GetInstance()->currentScene = Scene::TITLE;
		SceneManager::GetInstance()->isReset = true;
	}
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
		int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
		Gotoxy(0, GetConsoleResolution().Y / 4);
		int player1 = (player1Win * 10) + 1;
		int player2 = (player2Win * 10) + 2;
		for (int i = 0; i < playerWinCheckMessage[player1].size(); i++)
		{
			wcout << playerWinCheckMessage[player1][i] << '\n';
		}
		wcout << endl;
		Gotoxy(0, GetConsoleResolution().Y / 2);
		for (int i = 0; i < playerWinCheckMessage[player2].size(); i++)
		{
			wcout << playerWinCheckMessage[player2][i] << '\n';
		}
		wcout << endl;
		int wcoutmode = _setmode(_fileno(stdout), coutmode);
	}
	else
	{
		if (isPlayer1Win)
		{
			Gotoxy(GetConsoleResolution().X / 2, GetConsoleResolution().Y / 2);
			for (int i = 0; i < playerWinMessage[1].size();i++) {
				wcout << playerWinMessage[1][i] << '\n';
			}
		}
		else
		{
			Gotoxy(GetConsoleResolution().X / 2, GetConsoleResolution().Y / 2);
			for (int i = 0; i < playerWinMessage[2].size();i++) {
				wcout << playerWinMessage[2][i] << '\n';
			}
		}
	}
}

void PlayerWinCheck::PlayerWinCheckAscii()
{
	playerWinCheckMessage.insert({ 1,
		{
           L"█████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗██╗███╗   ██╗            ██████╗"
          ,L"█╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██║████╗  ██║    ██╗    ██╔═████╗"
          ,L"█████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║██╔██╗ ██║    ╚═╝    ██║██╔██║"
          ,L"█╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║██║╚██╗██║    ██╗    ████╔╝██║"
          ,L"█║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝██║██║ ╚████║    ╚═╝    ╚██████╔╝"
          ,L"═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝            ╚═════╝"
		}
		});
	playerWinCheckMessage.insert({ 11,
		{
			 L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗██╗███╗   ██╗            ██╗"
			,L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██║████╗  ██║    ██╗    ███║"
			,L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║██╔██╗ ██║    ╚═╝    ╚██║"
			,L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║██║╚██╗██║    ██╗     ██║"
			,L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝██║██║ ╚████║    ╚═╝     ██║"
			,L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝            ╚═╝"
		}
		});
	playerWinCheckMessage.insert({ 2,
		{
			 L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗     ██╗    ██╗██╗███╗   ██╗            ██████╗"
			,L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗    ██║    ██║██║████╗  ██║    ██╗    ██╔═████╗"
			,L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝    ██║ █╗ ██║██║██╔██╗ ██║    ╚═╝    ██║██╔██║"
			,L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝     ██║███╗██║██║██║╚██╗██║    ██╗    ████╔╝██║"
			,L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗    ╚███╔███╔╝██║██║ ╚████║    ╚═╝    ╚██████╔╝"
			,L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝            ╚═════╝"

		} 
	});

	playerWinCheckMessage.insert({ 12,
		{
			 L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗     ██╗    ██╗██╗███╗   ██╗            ██╗"
			,L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗    ██║    ██║██║████╗  ██║    ██╗    ███║"
			,L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝    ██║ █╗ ██║██║██╔██╗ ██║    ╚═╝    ╚██║"
			,L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝     ██║███╗██║██║██║╚██╗██║    ██╗     ██║"
			,L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗    ╚███╔███╔╝██║██║ ╚████║    ╚═╝     ██║"
			,L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝            ╚═╝"
		}
		});

	playerWinMessage.insert({ 1,
		{
			 L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗██╗███╗   ██╗██╗██╗"
			,L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██║████╗  ██║██║██║"
			,L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║██╔██╗ ██║██║██║"
			,L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║██║╚██╗██║╚═╝╚═╝"
			,L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝██║██║ ╚████║██╗██╗"
			,L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝╚═╝"
		}
		});
	playerWinMessage.insert({ 2,
		{
			 L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗     ██╗    ██╗██╗███╗   ██╗██╗██╗"
			,L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗    ██║    ██║██║████╗  ██║██║██║"
			,L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝    ██║ █╗ ██║██║██╔██╗ ██║██║██║"
			,L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝     ██║███╗██║██║██║╚██╗██║╚═╝╚═╝"
			,L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗    ╚███╔███╔╝██║██║ ╚████║██╗██╗"
			,L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝╚═╝"
		}
		});

}

PlayerWinCheck::~PlayerWinCheck()
{
}
