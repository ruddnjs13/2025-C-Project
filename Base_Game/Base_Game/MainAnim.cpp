#include "MainAnim.h"


void MainAnim::BalloonAsciiInit()
{
    BalloonAscii.insert({ 1,
        {
		}
		});
}

MainAnim::MainAnim()
{
    BalloonAsciiInit();
}


void MainAnim::SetRandomColor()
{
    /*std::random_device rd;
    std::mt19937 generator(rd());


    colorArr.clear();
    std::vector<COLOR> colors = { COLOR::BLUE,COLOR::GREEN , COLOR::RED,COLOR::MINT,COLOR::YELLOW,COLOR::GRAY };
    std::shuffle(colors.begin(), colors.end(), rd);
    for (int i = 0; i < colors.size();i++)
    {
        colors.push_back(colors[i]);
    }*/
}

void MainAnim::MainAnimPlay()
{
    AnimUpdate();
    AnimRender();
}

void MainAnim::AnimUpdate()
{
}

void MainAnim::AnimRender()
{
    int coloridx = 0;
    SetColor(COLOR::RED, COLOR::BLACK);
    int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);
    for (int i = 0; i < BalloonAscii[1].size(); i++) 
    {
        wcout << BalloonAscii[1][i] << '\n';
    }
    int wcoutmode = _setmode(_fileno(stdout), coutmode);

}
