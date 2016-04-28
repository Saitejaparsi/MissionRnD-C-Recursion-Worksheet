/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/
#include "stdafx.h"
#include<stdlib.h>
int *spiral_wrapper(int **input_array, int *res, int rows, int columns, int x1, int x2, int y1, int y2, int i)
{
	int temp;
	if (i > rows*columns - 1)
	{
		return res;
	}
	else
	{
		for (temp = y1; temp <= y2; temp = temp + 1)
		{
			res[i] = input_array[x1][temp];
			i++;
		}
		x1++;
		for (temp = x1; temp <= x2; temp = temp + 1)
		{
			res[i] = input_array[temp][y2];
			i++;
		}
		y2--;
		if (x1 < x2)
		{
			for (temp = y2; temp >= y1; temp -= 1)
			{
				res[i] = input_array[x2][temp];
				i++;
			}
			x2--;
		}
		if (y1 < y2)
		{
			for (temp = x2; temp >= x1; temp -= 1)
			{
				res[i] = input_array[temp][y1];
				i++;
			}
			y1++;
		}
		if (i == rows*columns - 1)
		{
			if (x1 == y1 && x2 == y2)
				res[i] = input_array[x1][y2];
			return res;
		}
	}
	return spiral_wrapper(input_array, res, rows, columns, x1, x2, y1,y2, i);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int *res = (int *)malloc(sizeof(int)*(rows*columns));
	int i = 0, x1 = 0, x2 = rows - 1, y1 = 0, y2 = columns - 1;
	res = spiral_wrapper(input_array, res, rows, columns, x1, x2, y1, y2, i);
	return res;
}