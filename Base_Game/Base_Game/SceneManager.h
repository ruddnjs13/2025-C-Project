#pragma once
class SceneManager
{
private:
	static SceneManager* Instance;
	SceneManager();
	~SceneManager();
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new SceneManager;
		}
		return Instance;
	}

};

