#include <stdio.h>
#include <string.h>

char bracket[51];

char pop() // 맨 뒤에 있는 괄호를 뺴고 리턴하는 함수
{
    int len;
    char tmp;
    len = strlen(bracket);
    tmp = bracket[len - 1];
    bracket[len - 1] = '\0';

    return tmp;
}

void reset() // 배열을 초기화하는 함수
{
    int len;
    len = strlen(bracket);

    for (int i = 0; i < len; i++)
        bracket[i] = '\0';
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int size, flag = 0;
        scanf("%s", bracket);
        size = strlen(bracket); // 길이만큼만 봐주기 위하여
        for (int j = 0; j < size; j++)
        {
            char tmp;
            tmp = pop();

            if (tmp == ')') // 빼준 것이 닫는 괄호면 +1
                flag++;
            else // 빼준 것이 여는 괄호면 -1
                flag--;

            if (flag < 0) // 여는 괄호가 먼저 나오면 닫질 못하기에 바로 종료
                break;
        }

        if (flag) // 0이 아니면 짝이 안맞는 것
            printf("NO\n");
        else // 0이여야 짝이 맞는다
            printf("YES\n");

        reset(); // 배열 초기화
    }
    return 0;
}