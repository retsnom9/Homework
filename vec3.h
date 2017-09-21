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

	vec3<T> vec3<T>::operator+(const vec3 &newvec3);
	vec3<T> vec3<T>::operator-(const vec3 &newvec3);
	void vec3<T>::operator+=(const vec3 &newvec3);
	void vec3<T>::operator-=(const vec3 &newvec3);
	void vec3<T>::operator=(const vec3 &newvec3);
	bool vec3<T>::operator==(const vec3 &newvec3);
	void normalize();
	void zero();
	bool is_zero() const;
	T distance_to(vec3 vec);
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
bool vec3<T>::is_zero() const {return x == 0 && y == 0 && z == 0;}

template <class T>
T vec3<T>::distance_to(vec3 vec)
{
	return sqrtf((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y) + (z - vec.z) * (z - vec.z));
}

template <class T>
vec3<T> vec3<T>::operator+(const vec3 &newvec3)
{
	return vec3<T>(x + newvec3.x, y + newvec3.y, z + newvec3.z);
}

template <class T>
vec3<T> vec3<T>::operator-(const vec3 &newvec3)
{
	return vec3<T>(x - newvec3.x, y - newvec3.y, z - newvec3.z);
}

template <class T>
void vec3<T>::operator+=(const vec3 &newvec3)
{
	x += newvec3.x;
	y += newvec3.y;
	z += newvec3.z;
}

template <class T>
void vec3<T>::operator-=(const vec3 &newvec3)
{
	x -= newvec3.x;
	y -= newvec3.y;
	z -= newvec3.z;
}

template <class T>
void vec3<T>::operator=(const vec3 &newvec3)
{
	x = newvec3.x;
	y = newvec3.y;
	z = newvec3.z;
}

template <class T>
bool vec3<T>::operator==(const vec3 &newvec3)
{
	return x == newvec3.x && y == newvec3.y && z == newvec3.z;
}

template <class T>
void vec3<T>::print() const
{
	printf("(%f, %f, %f)", vec.x, vec.y, vec.z);
}

#endif