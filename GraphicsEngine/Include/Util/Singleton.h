#pragma once
template <typename T>
class Singleton
{
public:
	static T& instance()
	{
		static T _instance;
		return _instance;
	}
protected:
	explicit Singleton<T>() { }

};