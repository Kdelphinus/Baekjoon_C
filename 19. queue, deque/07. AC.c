/**
 * @file 07. AC.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-03 21:52:53
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>

int start, end; // 주어진 정수 배열의 시작과 끝 인덱스

void D(int flag, char orders[], char numbers[]) // 가장 앞의 숫자를 제거하는 함수
{
    if (flag) // 리버스 상태일 때
    {
        end -= 2;               // 뒤에 것을 제거한다(']'와 숫자)
        numbers[end - 1] = ']'; // ','를 ']'로 바꾼다
    }
    else // 리버스 상태가 아닐 때
    {
        start += 2;           // 앞에 것을 제거한다('['와 숫자)
        numbers[start] = '['; // ','를 '['로 바꾼다
    }
}

void AC(int n, char orders[], char numbers[])
{
    int size, flag = 0; // 명령의 개수, 리버스 유무(1이 리버스 상태)

    size = strlen(orders); // 명령의 개수
    start = 0;             // 배열의 시작 인덱스
    end = strlen(numbers); // 배열의 끝 인덱스

    for (int i = 0; i < size; i++)
    {
        if (orders[i] == 'R') // 명령이 리버스이면
        {
            if (flag)
                flag = 0;
            else
                flag = 1;
        }
        else
        {
            if (end - start < 3) // 길이가 4보다 작으면 숫자가 들어갈 수 없다
            {
                printf("error\n");
                return;
            }
            D(flag, orders, numbers);
        }
    }

    if (flag)
    {
        printf("[");
        for (int i = end - 2; i > start; i--)
            printf("%c", numbers[i]);
        printf("]");
    }
    else
    {
        for (int i = start; i < end; i++)
            printf("%c", numbers[i]);
    }
    printf("\n");
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int n;
        char numbers[300000] = {0};
        char orders[100001] = {0};
        scanf("%s", orders);
        scanf("%d", &n);
        scanf("%s", numbers);

        AC(n, orders, numbers);
    }
    return 0;
}