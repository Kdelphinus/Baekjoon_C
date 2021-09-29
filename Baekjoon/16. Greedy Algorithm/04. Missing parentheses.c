/**
 * @file 04. Missing parentheses.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-17 22:48:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_value(char str[])
{
    int result = 0, size, i = 0, j = 0, flag = 0; // ��� ��, ���ڿ� ����, ���ڿ� Ž�� �ε���, �ӽ� ���� �ε���, -��ȣ�� ���Դ°�
    char tmp[6];                                  // �ӽ� ���� �迭

    size = strlen(str); // ���ڿ��� ����

    while (i < size)
    {
        if (flag) // -�� ���� �ڷ� ��� ���ش�
        {
            if (str[i] == '+' || str[i] == '-')
            {
                result -= atoi(tmp); // ���ڿ��� ���������� ��ȯ�Ͽ� ����
                j = 0;
                for (int k = 0; k < 6; k++) // �ӽ� ���� �迭 �ʱ�ȭ
                    tmp[k] = '\0';
            }
            else
            {
                tmp[j] = str[i]; // �ӽ� ���� �迭�� ���ڿ� ����
                j++;
            }
            i++;
        }
        else // -�� ������ �ʾҴٸ�
        {
            if (str[i] == '+') // �����ְų�
            {
                result += atoi(tmp);
                j = 0;
                for (int k = 0; k < 6; k++)
                    tmp[k] = '\0';
            }
            else if (str[i] == '-') // ���ְ� -�� ���Դٰ� ����
            {
                result += atoi(tmp);
                flag = 1;
                j = 0;
                for (int k = 0; k < 6; k++)
                    tmp[k] = '\0';
            }
            else
            {
                tmp[j] = str[i];
                j++;
            }
            i++;
        }
    }

    // ������ ���� ���
    if (flag)
        result -= atoi(tmp);
    else
        result += atoi(tmp);

    return result;
}

int main()
{
    char str[51];
    scanf("%s", str);

    printf("%d", min_value(str));

    return 0;
}