#pragma once  
#include <io.h>  
#include <fcntl.h>  
#include "Console.h"  
#include "MainAnim.h"
#include "SceneManager.h"  
#include "KeyController.h" 
class MainMenu  
{  
public:  
MainMenu();  
~MainMenu();  
private:  
Menu curMenu;
MainAnim* anim;
public:  
void MainMenuScene();  
void MainMenuInit();  
void MainMenuUpdate();  
void MainMenuRender();  
Menu GetCurMenu();  
};
