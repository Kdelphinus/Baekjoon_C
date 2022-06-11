/**
 * @file 03. 01tile.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 01Ÿ���� ������ �Ǻ���ġ ������ ���� ���¸� ���δ�
 * @date 2021-06-12 16:55:57
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int fib(int len)
{
	int current = 1, previous = 0, temp;

	for (int i = 1; i <= len; i++)
	{
		temp = current % 15746;					// ���簪�� �ӽ÷� ����
		current = (current + previous) % 15746; // �������� ���簪�� ���� ���� ���簪���� �ֽ�ȭ
		previous = temp;						// ���� ���簪�� ���������� �ֽ�ȭ
	}

	return current;
}

int main()
{
	int len;
	scanf("%d", &len);

	printf("%d\n", fib(len));

	return 0;
}