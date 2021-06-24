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

        fflush(stdin); // 뛰어쓰기가 들어간 문장을 입력받으면 \n이 남아있기에 입력버퍼를 비워야 한다

        fgets(string, 102, stdin); // fgets는 '\n'까지 입력받음
        //scanf("%[^\n]s ", string); // 여기선 이상없으나 백준에선 무한루프에 갇혀버림
        len = strlen(string);

        if (len == 2 && string[0] == '.')
            break;

        for (int i = 0; i < len; i++)
        {
            char tmp;
            tmp = pop();

            if (tmp == ')') // 소괄호는 1로 표시
            {
                small_flag++;
                check[j++] = 1;
            }
            else if (tmp == '(') // 현재 닫아야 할 괄호가 소괄호인지 확인하고 아니면 음수로 만들어줌
            {
                small_flag--;
                j--;
                if (check[j] != 1)
                    small_flag -= 1000;
                check[j] = 0;
            }
            else if (tmp == ']') // 대괄호는 -1로 표시
            {
                big_flag++;
                check[j++] = -1;
            }
            else if (tmp == '[') // 현재 닫아야 할 괄호가 대괄호인지 확인하고 아니면 음수로 만들어줌
            {
                big_flag--;
                j--;
                if (check[j] != -1)
                    big_flag -= 1000;
                check[j] = 0;
            }

            if (big_flag < 0 || small_flag < 0) // 하나라도 음수면 괄호가 맞지 않기에 바로 종료
                break;
        }

        if (big_flag == 0 && small_flag == 0)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}