/**
 * @file 05. stack array.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-25 20:25:22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

char stack[1000000], anw[1000000];

void stack_array(int sol[], int num)
{
    // i: �������� �� ���ڸ���Ʈ(number)�� �ε���
    // j: ���ϴ� �迭(sol)�� �ε���
    // k: ������ �ε���
    // l: ����� ����� �迭(anw)�� �ε���
    // number: ���ڰ� ������������ ����� �迭
    // anw: ����� ����� �迭
    // stack: ���� ������ �� �迭
    int i = 0, j = 0, k = 0, l = 0, number[num];

    for (int b = 1; b <= num; b++) // ���ڸ� ������������ ����
        number[b - 1] = b;

    while (1)
    {
        if ((sol[j] != stack[k - 1] && k - 1 >= 0) || strlen(stack) == 0) // ���� ���� �� ���ڿ� ���ϴ� �迭�� ���ڰ� ����ġ�ϰų� ���ÿ� ���ڰ� ���� ���
        {
            if (i == num) // �ٵ� �̹� number�� �� ���Ҵٸ�
            {
                printf("NO"); // �Ұ���
                break;
            }
            stack[k++] = number[i++]; // ���ÿ� ���� number�� ���ڸ� �߰�
            anw[l++] = '+';           // push ��ɾ� �߰�
        }
        else // ���� ���� ���� �� ���ڿ� ���ϴ� �迭�� ���ڰ� ��ġ�ϸ�
        {
            anw[l++] = '-';  // pop ��ɾ� �߰�
            k--;             // ������ �ε����� �ϳ� ���̰�
            stack[k] = '\0'; // ���� ������ ���ڸ� ����
            j++;             // ���ϴ� �迭�� �ε����� �ϳ� �ø���
        }

        if (j == num) // ���ϴ� �迭�� ������ �� ������ ��
        {
            if (strlen(stack) == 0) // ������ ����ִٸ�
            {
                int size;
                size = strlen(anw);
                for (int a = 0; a < size; a++) // ��ɾ ����ϰ�
                    printf("%c\n", anw[a]);
                break;
            }
            else // �����ִٸ�
            {
                printf("NO"); // �Ұ����ϴ�
                break;
            }
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    int sol[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &sol[i]);

    stack_array(sol, num);

    return 0;
}