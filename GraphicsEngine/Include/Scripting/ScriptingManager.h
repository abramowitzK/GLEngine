#pragma once
#include "ScriptCommon.h"
#include "LuaEngine.h"
#include "../Util/Singleton.h"
#include "../Interfaces.h"
#include "../Scripting/ExposedToScript.h"
class ScriptingManager : public Singleton<ScriptingManager>, public IManager
{
public:
	void StartUp() override;
	void ShutDown() override;
private:
	LuaEngine m_engine;

};