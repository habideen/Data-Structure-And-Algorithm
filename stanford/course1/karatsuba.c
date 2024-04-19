#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * countNumber - returns the length of a number
 * @num: number to find its length
 * Return: the lenght of @num
 */
int countNumber(int num)
{
	int count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}

	return count;
}

/**
 * karatsubaMultiplication - multiply two numbers using karatsuba method
 * @num1: first operand to multiply
 * @num2: second operand to multiply
 * Return: return the product of num1 and num2
 */
int karatsubaMultiply(int num1, int num2)
{
	/* declare variables at the beginning */
	int num1Len, num2Len, maxCount, halfCount;
	long long high1, low1, high2, low2, z0, z1, z2;

	/* base case */
	if (num1 < 10 || num2 < 10)
	{
		return num1 * num2;
	}

	num1Len = countNumber(num1);
	num2Len = countNumber(num2);
	maxCount = (num1Len > num2Len) ? num1Len : num2Len;
	halfCount = maxCount / 2;

	/* split the numbers */
	high1 = num1 / pow(10, halfCount);
	low1 = num1 % (long long)pow(10, halfCount);
	high2 = num2 / pow(10, halfCount);
	low2 = num2 % (long long)pow(10, halfCount);

	/* perform recursive calls */
	z0 = karatsubaMultiply(low1, low2);
	z1 = karatsubaMultiply(high1, high2);
	z2 = karatsubaMultiply((low1 + high1), (low2 + high2));

	return z2 * (long long)pow(10, 2 * halfCount) + (z2 - z1 - z0) * (long long)pow(10, halfCount) + z0;
}

/**
 * main: program entry point
 * Return:
 */
int main(int argc, char const *argv[])
{
	(void)argc;
	int product;

	if (argc < 3)
	{
		printf("Usage: %s <num1> <num2>\n", argv[0]);
		return 1;
	}

	product = karatsubaMultiply(atoi(argv[1]), atoi(argv[2]));
	printf("The karatsuba multipliction of %d and %d is %d", atoi(argv[1]), atoi(argv[2]), product);

	return 0;
}
