#pragma once
//Renderable interface
class IRenderable
{
public:
	virtual void Render() = 0;
};
//Interface for all subsystem managers
class IManager
{
public:
	virtual void StartUp() = 0;
	virtual void ShutDown() = 0;
};