/**
 * @file 13. electric flex.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-15 16:20:08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int start; // ������ ��������
	int end;   // ������ ������
} point;

point electric_flex[101];

int num, remaining;
int dp[101]; // �� ��ġ���� ���� ���� �������� ��ġ�� �� �ִ� ����

void merge(point *arr, int low, int mid, int high) // �������� ������ �Լ�
{
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high)
	{
		if (arr[i].start < arr[j].start)
			electric_flex[k++] = arr[i++];
		else if (arr[i].start > arr[j].start)
			electric_flex[k++] = arr[j++];
		else
		{
			if (arr[i].end < arr[j].end)
				electric_flex[k++] = arr[i++];
			else if (arr[i].end > arr[j].end)
				electric_flex[k++] = arr[j++];
			else
			{
				electric_flex[k++] = arr[i++];
				electric_flex[k++] = arr[j++];
			}
		}
	}

	if (i <= mid)
	{
		while (i <= mid)
			electric_flex[k++] = arr[i++];
	}

	if (j <= high)
	{
		while (j <= high)
			electric_flex[k++] = arr[j++];
	}

	for (k = low; k <= high; k++)
		arr[k] = electric_flex[k];
}

void mergeSort(point *arr, int low, int high) // �������� ������ �Լ�
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int remove_flex(point *wire)
{
	dp[0] = 1;
	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (wire[i].start > wire[j].start && wire[i].end > wire[j].end && dp[i] < dp[j]) // �� ��ġ���� ��������, �������� ��� �۾ƾ� �Ѵ�
				dp[i] = dp[j];
		}
		dp[i]++;

		if (remaining < dp[i])
			remaining = dp[i];
	}

	return num - remaining;
}

int main()
{
	scanf("%d", &num);
	point *wire = (point *)malloc(sizeof(point) * num);
	for (int i = 0; i < num; i++)
		scanf("%d %d", &wire[i].start, &wire[i].end);

	mergeSort(wire, 0, num - 1);

	printf("%d\n", remove_flex(wire));

	return 0;
}