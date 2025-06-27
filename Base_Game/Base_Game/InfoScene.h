#pragma once
#include <io.h>  
#include <fcntl.h>  
#include "Console.h"  
#include "SceneManager.h"  
#include "KeyController.h"  
class InfoScene
{
public:
	void Info();
	void InfoUpdate();
	void InfoRender();
	Menu GetCurMenu();
};

