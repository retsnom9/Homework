#include <stdio.h>
#include "vec3.h"

int main()
{
	vec3<float> vec(3, 2, -4);
	vec3<float> vec2(4, 2, 6);

	printf("Vectors are:\n");
	vec.print();
	printf("\n");
	vec2.print();

	printf("\nThe distance between them is: %f", vec.distance_to(vec2));

	printf("\nvec1 - vec2 = ");
	vec.operator-=(vec2);
	vec.print();

	if (vec.is_zero())
	{
		printf("\nThe vector1 is zero: ");
		vec.print();
	}
	else
	{
		printf("\nThe vector1 isn't zero: ");
		vec.print();
	}

	vec.zero();

	if (vec.is_zero())
	{
		printf("\nThe vector1 is zero: ");
		vec.print();
	}
	else
	{
		printf("\nThe vector1 isn't zero: ");
		vec.print();
	}

	vec2.normalize();
	printf("\nNormalized vector2 equals:\n");
	vec2.print();

	if (vec.operator==(vec2))
	{
		printf("\nvec1 and vec2 are equal:\n");
		vec.print();
		printf("\n");
		vec2.print();
	}
	else
	{
		printf("\nvec1 and vec2 are not equal:\n");
		vec.print();
		printf("\n");
		vec2.print();
	}

	vec.operator=(vec2);

	if (vec.operator==(vec2))
	{
		printf("\nvec1 and vec2 are equal:\n");
		vec.print();
		printf("\n");
		vec2.print();
	}
	else
	{
		printf("\nvec1 and vec2 are not equal:\n");
		vec.print();
		printf("\n");
		vec2.print();
	}

	getchar();
	return 0;
}