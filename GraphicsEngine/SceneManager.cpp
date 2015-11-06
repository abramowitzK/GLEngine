#include "SceneManager.h"

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
	delete m_root;
}

void SceneManager::InitScene()
{
	m_root = new GameObject();
}
