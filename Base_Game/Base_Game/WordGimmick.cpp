#include "WordGimmick.h"

void WordGimmick::Init()
{
    char keyChar = 'A';
    vector<string> temp;
    string line;

    std::ifstream file("Alphabet.txt");

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.empty())
            {
                if (!temp.empty())
                {
                    asciiMap.insert({ keyChar, temp });
                    temp.clear();
                    keyChar++;
                }
            }
            else
            {
                temp.push_back(line);
            }
        }
    }
}

void WordGimmick::Interact(char btnType)
{
    if (slotIdx > 4) return;

    submitArr[slotIdx++] = btnType;
}

void WordGimmick::GimmickRender()
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < WORD_HEIGHT; ++j)
		{
			Gotoxy(start_x + (WORD_WIDTH * i), start_y + j);
			cout << asciiMap[submitArr[i]][j] << '\n';
		}
    }
}

void WordGimmick::Submit()
{
}
