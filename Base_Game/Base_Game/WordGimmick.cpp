#include "WordGimmick.h"

void WordGimmick::Init()
{
    //char keyChar = 'A';
    //vector<wstring> temp;
    //wstring line;

    //std::wifstream file("Ascii_Alphabet.txt");

    //if (file.is_open())
    //{
    //    while (getline(file, line))
    //    {
    //        if (line.empty())
    //        {
    //            if (!temp.empty())
    //            {
    //                asciiMap.insert({ keyChar, temp });
    //                temp.clear();
    //                keyChar++;
    //            }
    //        }
    //        else
    //        {
    //            temp.push_back(line);
    //        }
    //    }

    //    // 마지막 글자 저장 누락 방지
    //    if (!temp.empty())
    //    {
    //        asciiMap.insert({ keyChar, temp });
    //    }
    //}
    //else
    //{
    //    cout << "알파벳 아스키 파일 초기화 실패" << endl;
    //}

    vector<wstring> temp;

    temp = { L" █████╗   ",
        L"██╔══██╗", 
        L"███████║    ", 
        L"██╔══██║    ",
        L"██║  ██║    ",
        L"╚═╝  ╚═╝  " };
    asciiMap.insert({ 'A', temp });
}

void WordGimmick::Interact(char btnType)
{
}

void WordGimmick::GimmickRender()
{
			int coutmode = _setmode(_fileno(stdout), _O_U16TEXT);


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < WORD_HEIGHT; ++j)
		{

			Gotoxy(start_x + (WORD_WIDTH * i), start_y + j);
			wcout << asciiMap[word[slotIdx]][j] << '\n';

		}
	}
	
			int wcoutmode = _setmode(_fileno(stdout), coutmode);
}
