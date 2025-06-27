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
	cout << "Player1 ����Ű : �̵� wasd, ���� ���� �� �ܾ� ���� �� �߻� : Spacebar" << '\n';
	cout << "Player2 ����Ű : �̵� ����Ű, ���� ���� �� �ܾ� ���� �� �߻� : Enter" << '\n';
	cout << "���� ���߱� : �� 6���� �����߿��� ������ ��(�ߺ�����)5���� ������� ���߸�ȴ�." << '\n';
	cout << "�ܾ���߱� : ���� �ܾ ���߸�Ǵ�" << '\n';
	cout << "���߱� ������ Ʋ���� ������ ������ �ʷϻ��� ����ش�. �ܾ���߱�� ��Ȳ������ �ܾ ��������� ��ġ�� �ٸ��� ����ش�." << '\n';
	cout << "���ð��� : ������ ���� ��� �÷��̾�� ������ �� ���� ���� �Ǵ� ����" << '\n';
	cout << "�¸����� : 3���� �̴ϰ����� 2���� �̱� �÷��̾ �¸�";
	Gotoxy(2, resolution.Y / 2 +8);
	cout << "���θ޴���";
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
