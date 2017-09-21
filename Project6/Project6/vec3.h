#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdio.h>

template <class T>
class vec3
{
public:
	vec3(T x, T y, T z);
	~vec3();

	vec3<T> vec3<T>::operator+(const vec3 &vec3);
	vec3<T> vec3<T>::operator-(const vec3 &vec3);
	void vec3<T>::operator+=(const vec3 &vec3);
	void vec3<T>::operator-=(const vec3 &vec3);
	void vec3<T>::operator=(const vec3 &vec3);
	bool vec3<T>::operator==(const vec3 &vec3);
	void normalize();
	void zero();
	bool is_zero() const;
	T distance_to(vec3 vec3);
	void print() const;

private:
	T x;
	T y;
	T z;
};

template <class T>
vec3<T>::vec3(T x, T y, T z) : x(x), y(y), z(z) {}

template <class T>
vec3<T>::~vec3() {}

template <class T>
void vec3<T>::normalize()
{
	int lenght = sqrtf(x * x + y * y + z * z);
	x /= lenght;
	y /= lenght;
	z /= lenght;
}

template <class T>
void vec3<T>::zero()
{
	x = 0;
	y = 0;
	z = 0;
}

template <class T>
bool vec3<T>::is_zero() const { return x == 0 && y == 0 && z == 0; }

template <class T>
T vec3<T>::distance_to(vec3 vec3)
{
	return (sqrtf((x - vec3.x) * (x - vec3.x) + (y - vec3.y) * (y - vec3.y) + (z - vec3.z) * (z - vec3.z)));
}

template <class T>
vec3<T> vec3<T>::operator+(const vec3 &_vec3)
{
	vec3 Vec3 = _vec3;

	Vec3.x += x;
	Vec3.y += y;
	Vec3.z += z;

	return _vec3;
}

template <class T>
vec3<T> vec3<T>::operator-(const vec3 &_vec3)
{
	vec3 Vec3 = _vec3;

	Vec3.x -= x;
	Vec3.y -= y;
	Vec3.z -= z;


	return _vec3;
}

template <class T>
void vec3<T>::operator+=(const vec3 &vec3)
{
	x += vec3.x;
	y += vec3.y;
	z += vec3.z;
}

template <class T>
void vec3<T>::operator-=(const vec3 &vec3)
{
	x -= vec3.x;
	y -= vec3.y;
	z -= vec3.z;
}

template <class T>
void vec3<T>::operator=(const vec3 &vec3)
{
	x = vec3.x;
	y = vec3.y;
	z = vec3.z;
}

template <class T>
bool vec3<T>::operator==(const vec3 &vec3)
{
	return x == vec3.x && y == vec3.y && z == vec3.z;
}

template <class T>
void vec3<T>::print() const
{
	printf("(%.2f, %.2f, %.2f)", x, y, z);
}

#endif