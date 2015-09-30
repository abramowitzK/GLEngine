#pragma once
#include <type_traits>
#include <string>
#include <sstream>

template<typename T>
class Vector2
{
public:
	Vector2() 
	{
			
	}
	Vector2(T x, T y)
	{
		m_data[0] = x;
		m_data[1] = y;
	}
	~Vector2() 
	{

	}
	inline T GetX()
	{
		return m_data[0];
	}
	inline T GetY()
	{
		return m_data[1];
	}
	inline void SetX(T value)
	{
		m_data[0] = value;
	}
	inline void SetY(T value)
	{
		m_data[1] = value;
	}
	inline T Dot(Vector2<T> vec2)
	{
		return GetX()*vec2.GetX() + GetY()*vec2.GetY();
	}
	std::string ToString()
	{
		std::ostringstream os;
		os << "(" << m_data[0] << ", " << m_data[1] << ")";
		return os.str();
	}
private:
	T m_data[2];

};
template<typename T>
class Vector3
{
public:
	Vector3() {}
	~Vector3() {}
private:
};

// Typedefs to make life easier
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;
typedef Vector2<int> Vector2i;
typedef Vector2<long> Vector2l;

//Vector 3 typedefs
typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;
typedef Vector3<int> Vector3i;
typedef Vector3<long> Vector3l;