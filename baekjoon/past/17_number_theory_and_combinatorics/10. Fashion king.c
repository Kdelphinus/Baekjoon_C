/**
 * @file 10. Fashion king.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-23 17:43:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) // ���ڿ� �������� ����(�� �������� �����ϱ⿡)
{
    return -strcmp((char *)a, (char *)b);
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int num;
        scanf("%d", &num);
        int k = 0, kind_num[31] = {0}, cnt = 1, anw = 1; // �� ����, ���� ������ � ����ִ��� ������ ����Ʈ, ���� ������ ���� ����, ����� ��
        char name[31][21], kind[31][21] = {0};           // �̸��� ������ �迭, ���� ������ ������ �迭(�ʱ�ȭ��Ŵ)

        for (int j = 0; j < num; j++)
            scanf("%s %s", name[j], kind[j]);

        qsort(kind, sizeof(kind) / sizeof(kind[0]), sizeof(kind[0]), compare); // ���� �������� ��������(null���ڵ� �ֱ⿡ ������������ �Էµ� ���ڵ��� ���� ���̰� ��)

        for (int j = 1; j < num; j++)
        {
            if (strcmp(kind[j], kind[j - 1]) == 0) // ������ ������ ������ �߰��ϰ�
                cnt++;
            else // ������ �ٸ��ٸ�
            {
                kind_num[k++] = cnt; // ���ݱ��� ���� ���� ������ �����ϰ� �ε��� �̵�
                cnt = 1;             // ���� ���� �� �ʱ�ȭ
            }
        }
        if (num > 0)
            kind_num[k++] = cnt; // ������ ���� ���� ���� ����

        for (int j = 0; j < k; j++) // ���� ���� ����� ������ ���ϱ����� +1�� �Ͽ� ����
            anw *= kind_num[j] + 1;

        printf("%d\n", anw - 1); // �� ���� ��Ȳ�� ���� ���ؼ� -1�� ��
    }
    return 0;
}