#include "PlayerWinCheck.h"



PlayerWinCheck::PlayerWinCheck()
{
	PlayerWinCheckAscii();
}

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
		int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
		Gotoxy(0, GetConsoleResolution().Y / 4);
		for (int i = 0; i < playerWinMessage[1].size(); i++)
		{
			wcout << playerWinMessage[1][i] << '\n';
		}
		for (int i = 0; i < playerWinIntMessage[player1Win].size(); i++)
		{
			wcout << playerWinIntMessage[player1Win][i] << '\n';
		}
		wcout << endl;
		Gotoxy(0, GetConsoleResolution().Y / 2);
		for (int i = 0; i < playerWinMessage[2].size(); i++)
		{
			wcout << playerWinMessage[2][i] << '\n';
		}
		for (int i = 0; i < playerWinIntMessage[player2Win].size(); i++)
		{
			wcout << playerWinIntMessage[player1Win][i] << '\n';
		}
		wcout << endl;
		int wcoutmode = _setmode(_fileno(stdout), coutmode);
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

void PlayerWinCheck::PlayerWinCheckAscii()
{
	playerWinMessage.insert({ 1,
		{
			 L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗██╗███╗   ██╗"
			,L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██║████╗  ██║    ██╗"
			,L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║██╔██╗ ██║    ╚═╝"
			,L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║██║╚██╗██║    ██╗"
			,L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝██║██║ ╚████║    ╚═╝"
			,L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝"
		}
		});
	playerWinMessage.insert({ 2,
		{
			 L"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ██████╗     ██╗    ██╗██╗███╗   ██╗"
			,L"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚════██╗    ██║    ██║██║████╗  ██║    ██╗"
			,L"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     █████╔╝    ██║ █╗ ██║██║██╔██╗ ██║    ╚═╝"
			,L"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔═══╝     ██║███╗██║██║██║╚██╗██║    ██╗"
			,L"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ███████╗    ╚███╔███╔╝██║██║ ╚████║    ╚═╝"
			,L"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚══════╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝"
		} 
	});

	playerWinIntMessage.insert({ 0,
		{
			 L"██████╗"
		   ,L"██╔═████╗"
		   ,L"██║██╔██║"
		   ,L"████╔╝██║"
		   ,L"╚██████╔╝"
			,L"╚═════╝"
		}
		});

	playerWinIntMessage.insert({ 1,
		{
			 L" ██╗"
			,L"███║"
			,L"╚██║"
			,L" ██║"
			,L" ██║"
			,L" ╚═╝"
		}
		});

	playerWinIntMessage.insert({ 2,
		{
		   L"██████╗"
		  L"╚════██╗"
		   L"█████╔╝"
		  L"██╔═══╝"
		   L"███████╗"
		   L"╚══════╝"
		}
		});

}

PlayerWinCheck::~PlayerWinCheck()
{
}
