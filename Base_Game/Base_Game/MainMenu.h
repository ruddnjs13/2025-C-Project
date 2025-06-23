#pragma once  
#include <io.h>  
#include <fcntl.h>  
#include "Console.h"  
#include "SceneManager.h"  
#include "KeyController.h"  
class MainMenu  
{  
public:  
MainMenu();  
~MainMenu();  
private:  
Menu curMenu;  
public:  
void MainMenuScene();  
void MainMenuInit();  
void MainMenuUpdate();  
void MainMenuRender();  
Menu GetCurMenu();  
};
