#include "MainMenu.h"

MainMenu::MainMenu()
	:anim(nullptr)
{
	anim = new MainAnim;
	MainMenuInit();
}

MainMenu::~MainMenu()
{
	delete anim;
}

void MainMenu::MainMenuScene()
{
	while (SceneManager::GetInstance()->currentScene == Scene::TITLE)
	{

		MainMenuUpdate();
		FrameSync(60);
		MainMenuRender();
		Gotoxy(0, 0);
		anim->AnimUpdate();
		anim->AnimRender();
	}
}

void MainMenu::MainMenuInit()
{
}

void MainMenu::MainMenuUpdate()
{
	curMenu = GetCurMenu();
	switch (curMenu)
	{
	case Menu::START:
		system("cls");
		SceneManager::GetInstance()->currentScene = Scene::STAGESLECT;
		break;
	case Menu::INFO:
		SceneManager::GetInstance()->currentScene = Scene::INFO;
		break;
	case Menu::QUIT:
		SceneManager::GetInstance()->currentScene = Scene::QUIT;
		break;
	}
}

void MainMenu::MainMenuRender()
{
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 2;
	Gotoxy(0, y);
	int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
	    wcout <<L"   ██████╗  █████╗ ██████╗ ████████╗██╗   ██╗██████╗ ██╗ ██████╗ ████████╗"<<'\n';
		wcout <<L"   ██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚██╗ ██╔╝██╔══██╗██║██╔═══██╗╚══██╔══╝"<<'\n';
		wcout <<L"   ██████╔╝███████║██████╔╝   ██║    ╚████╔╝ ██████╔╝██║██║   ██║   ██║	"<<'\n';
		wcout <<L"   ██╔═══╝ ██╔══██║██╔══██╗   ██║     ╚██╔╝  ██╔══██╗██║██║   ██║   ██║	"<<'\n';
		wcout <<L"   ██║     ██║  ██║██║  ██║   ██║      ██║   ██║  ██║██║╚██████╔╝   ██║	"<<'\n';
		wcout <<L"   ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝╚═╝ ╚═════╝    ╚═╝	"<<'\n';

	int wcoutmode = _setmode(_fileno(stdout), coutmode);
	int x = resolution.X / 4 * 3;
	y = resolution.Y / 2;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "게임 종료";
}

Menu MainMenu::GetCurMenu()
{
	COORD resolution = GetConsoleResolution();
	int x = resolution.X / 4 * 3;
	static int y = resolution.Y / 2;
	static int originy = y;
	Key eKey = KeyController(0, false);
	// 2 
	switch (eKey)
	{
	case Key::UP:
		if (y > originy)
		{
			Gotoxy(x - 2, y);
			cout << " ";
			Gotoxy(x - 2, --y);
			cout << ">";
			Sleep(100);
		}
		break;
	case Key::DOWN:
		if (y < originy + 2)
		{
			Gotoxy(x - 2, y);
			cout << " ";
			Gotoxy(x - 2, ++y);
			cout << ">";
			Sleep(100);
			// 1 
		}
		break;
	case Key::SPACE:
		if (originy == y) return Menu::START;
		else if (originy + 1 == y) return Menu::INFO;
		else  if (originy + 2 == y) return Menu::QUIT;
		break;
	}
	return Menu::FAIL;
}
