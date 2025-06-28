#include "MainAnim.h"


void MainAnim::BalloonAsciiInit()
{
    BalloonAscii.insert({ 1,
        {
           L"           .-'''-.                                                "
          ,L"          /       '                                               "
          ,L"         |         |                                              "
          ,L"         |         |                                              "
          ,L"          '       /                                               "
          ,L"           '-._.-'                                                "
          ,L"              /                                                   "
          ,L"             /                                                    "
          ,L"             |                                                    "
          ,L"             /                                                    "
          ,L"             '                                                    "
		}
		});
}

MainAnim::MainAnim()
{
    BalloonAsciiInit();
}

void MainAnim::MainAnimPlay()
{
    AnimUpdate();
    AnimRender();
}

void MainAnim::AnimUpdate()
{
    for (auto& line : BalloonAscii[1])
    {
        std::rotate(line.begin(), line.begin() + 1, line.end());
    }
}

void MainAnim::AnimRender()
{
    int coloridx = 0;
    SetColor(colorArr[coloridx], COLOR::BLACK);
    int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
    for (int i = 0; i < BalloonAscii[1].size(); i++) 
    {
        wcout << BalloonAscii[1][i] << '\n';
    }
    coloridx++;
    SetColor(colorArr[coloridx], COLOR::BLACK);
    for (int i = 0; i < BalloonAscii[1].size(); i++)
    {
        wcout << BalloonAscii[1][i] << '\n';
    }
    coloridx++;
    SetColor(colorArr[coloridx], COLOR::BLACK);
    Gotoxy(0, GetConsoleResolution().Y -16);
    for (int i = 0; i < BalloonAscii[1].size(); i++)
    {
        wcout << BalloonAscii[1][i] << '\n';
    }
    coloridx++;
    SetColor(colorArr[coloridx], COLOR::BLACK);
    for (int i = 0; i < BalloonAscii[1].size(); i++)
    {
        int baseX = GetConsoleResolution().X / 2;
        int baseY = GetConsoleResolution().Y - 16;

        Gotoxy(baseX, baseY + i);
        std::wcout << BalloonAscii[1][i];
    }
    coloridx++;
    SetColor(colorArr[coloridx], COLOR::BLACK);
    for (int i = 0; i < BalloonAscii[1].size(); i++)
    {
        int baseX = GetConsoleResolution().X / 2;
        int baseY = 0;

        Gotoxy(baseX, baseY + i);
        std::wcout << BalloonAscii[1][i];
    }
    coloridx++;
    SetColor(colorArr[coloridx], COLOR::BLACK);
    for (int i = 0; i < BalloonAscii[1].size(); i++)
    {
        int baseX = GetConsoleResolution().X / 2;
        int baseY = GetConsoleResolution().Y/2 -12;

        Gotoxy(baseX, baseY + i);
        std::wcout << BalloonAscii[1][i];
    }
    int wcoutmode = _setmode(_fileno(stdout), coutmode);
    SetColor();
}
