/**
 * @file 06. Integer Triangle.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief �ؿ��� ���� �ö󰡴� ���
 * @date 2021-06-12 17:45:19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int size;
int triangle[501][501];

int max(int a, int b) // �ִ��� �����ϴ� �Լ�
{
	if (a > b)
		return a;
	else
		return b;
}

int max_sum()
{
	for (int i = size - 2; i >= 0; i--) // size - 1�ٺ��� �ؿ� �� �� ��, ū ���� ���ϸ鼭 ���� �ö�
	{
		for (int j = 0; j <= i; j++)
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
	}

	return triangle[0][0];
}

int main()
{
	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			scanf("%d", &triangle[i][j]);
	}

	printf("%d", max_sum());

	return 0;
}