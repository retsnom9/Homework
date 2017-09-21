#include <stdio.h>
#include "vec3.h"

int main()
{
	vec3<float> vec(3, 2, -4);
	vec3<float> vec2(4, 2, 6);
	vec3<float> vec3 = vec.operator+(vec2);

	printf("Vectors are:\n");
	vec.print();
	printf(" => vec1\n");
	vec2.print();
	printf(" => vec2");

	printf("\nvec1 + vec 2 = ");
	vec3.print();
	printf("\nvec1 - vec 2 = ");
	vec3 = vec.operator-(vec2);
	vec3.print();

	printf("\nThe distance between them is: %.2f", vec.distance_to(vec2));

	printf("\nvec1 will now be the result of vec1 - vec2 [");
	vec.operator-=(vec2);
	vec.print();
	printf("]");

	if (vec.is_zero())
	{
		printf("\nvec1 is zero: ");
		vec.print();
	}
	else
	{
		printf("\nvec1 isn't zero: ");
		vec.print();
	}

	vec.zero();

	if (vec.is_zero())
	{
		printf("\nvec1 is zero: ");
		vec.print();
	}
	else
	{
		printf("\nvec1 isn't zero: ");
		vec.print();
	}

	vec2.normalize();
	printf("\nNormalized vec2 equals:\n");
	vec2.print();

	if (vec.operator==(vec2))
	{
		printf("\nvec1 and vec2 are equal:\n");
		vec.print();
		printf(" => vec1\n");
		vec2.print();
		printf(" => vec2");
	}
	else
	{
		printf("\nvec1 and vec2 are not equal:\n");
		vec.print();
		printf(" => vec1\n");
		vec2.print();
		printf(" => vec2");
	}

	vec.operator=(vec2);

	if (vec.operator==(vec2))
	{
		printf("\nvec1 and vec2 are equal:\n");
		vec.print();
		printf(" => vec1\n");
		vec2.print();
		printf(" => vec2");
	}
	else
	{
		printf("\nvec1 and vec2 are not equal:\n");
		vec.print();
		printf(" => vec1\n");
		vec2.print();
		printf(" => vec2");
	}

	getchar();
	return 0;
}