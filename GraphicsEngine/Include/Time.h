#pragma once
class Time final
{
public:
	static double GetTime();
	static void SetDeltaTime(double dt);
	static double DeltaTime();

private:
	static double s_deltaTime;
};

