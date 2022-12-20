/**
 * @file 04. Balanced world.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-24 17:19:27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

char string[102];
int check[102];

char pop()
{
    int len;
    char tmp;
    len = strlen(string);
    tmp = string[len - 1];
    string[len - 1] = '\0';

    return tmp;
}

int main()
{
    int len, j, small_flag, big_flag;
    while (1)
    {
        small_flag = 0;
        big_flag = 0;
        j = 0;

        fflush(stdin); // �پ�Ⱑ �� ������ �Է¹����� \n�� �����ֱ⿡ �Է¹��۸� ����� �Ѵ�

        fgets(string, 102, stdin); // fgets�� '\n'���� �Է¹���
        //scanf("%[^\n]s ", string); // ���⼱ �̻������ ���ؿ��� ���ѷ����� ��������
        len = strlen(string);

        if (len == 2 && string[0] == '.')
            break;

        for (int i = 0; i < len; i++)
        {
            char tmp;
            tmp = pop();

            if (tmp == ')') // �Ұ�ȣ�� 1�� ǥ��
            {
                small_flag++;
                check[j++] = 1;
            }
            else if (tmp == '(') // ���� �ݾƾ� �� ��ȣ�� �Ұ�ȣ���� Ȯ���ϰ� �ƴϸ� ������ �������
            {
                small_flag--;
                j--;
                if (check[j] != 1)
                    small_flag -= 1000;
                check[j] = 0;
            }
            else if (tmp == ']') // ���ȣ�� -1�� ǥ��
            {
                big_flag++;
                check[j++] = -1;
            }
            else if (tmp == '[') // ���� �ݾƾ� �� ��ȣ�� ���ȣ���� Ȯ���ϰ� �ƴϸ� ������ �������
            {
                big_flag--;
                j--;
                if (check[j] != -1)
                    big_flag -= 1000;
                check[j] = 0;
            }

            if (big_flag < 0 || small_flag < 0) // �ϳ��� ������ ��ȣ�� ���� �ʱ⿡ �ٷ� ����
                break;
        }

        if (big_flag == 0 && small_flag == 0)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}