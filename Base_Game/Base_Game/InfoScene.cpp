#include "InfoScene.h"
#include "SceneManager.h"

void InfoScene::Info()
{
	while (SceneManager::GetInstance()->currentScene == Scene::INFO)
	{
		
		InfoUpdate();
		Gotoxy(0, 0);
		FrameSync(60);
		InfoRender();
	}
}

void InfoScene::InfoUpdate()
{
	GetCurMenu();
}

void InfoScene::InfoRender()
{
	COORD resolution = GetConsoleResolution();
	int y = resolution.Y / 2;

	Gotoxy(0, y);
	cout << "Player1 조작키 : 이동 wasd, 색깔 선택 및 단어 선택 및 발사 : Spacebar" << '\n';
	cout << "Player2 조작키 : 이동 방향키, 색깔 선택 및 단어 선택 및 발사 : Enter" << '\n';
	cout << "색깔 맞추기 : 총 6개에 색깔중에서 랜덤한 색(중복없음)5개를 순서대로 맞추면된다." << '\n';
	cout << "단어맞추기 : 영어 단어를 맞추면되는" << '\n';
	cout << "맞추기 게임은 틀리면 빨간색 맞으면 초록색을 띄워준다. 단어맞추기는 주황색으로 단어가 들어있지만 위치가 다를때 띄워준다." << '\n';
	cout << "슈팅게임 : 과녁을 맞춰 상대 플레이어보다 점수를 더 많이 내면 되는 게임" << '\n';
	cout << "승리조건 : 3개에 미니게임중 2개를 이긴 플레이어가 승리";
	Gotoxy(2, resolution.Y / 2 +8);
	cout << "메인메뉴로";
}

Menu InfoScene::GetCurMenu()
{
	Key eKey = KeyController(0, false);
	Gotoxy(1, GetConsoleResolution().Y / 2 + 8);
	cout << ">";
	if (eKey == Key::SPACE)
	{
		SceneManager::GetInstance()->currentScene = Scene::TITLE;
	}

	return Menu::FAIL;
}
