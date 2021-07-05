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
        if (numbers[end - 3] == ',') // 한 자리 숫자일 때
        {
            end -= 2;               // 뒤에 것을 제거한다(']'와 숫자)
            numbers[end - 1] = ']'; // ','를 ']'로 바꾼다
        }
        else if (numbers[end - 4] == ',') // 두 자리 숫자일 때
        {
            end -= 3;               // 뒤에 것을 제거한다(']'와 숫자)
            numbers[end - 1] = ']'; // ','를 ']'로 바꾼다
        }
        else if (numbers[end - 5] == ',') // 세 자리 숫자일 때
        {
            end -= 4;               // 뒤에 것을 제거한다(']'와 숫자)
            numbers[end - 1] = ']'; // ','를 ']'로 바꾼다
        }
    }
    else // 리버스 상태가 아닐 때
    {
        if (numbers[start + 2] == ',') // 한 자리 숫자일 때
        {
            start += 2;           // 앞에 것을 제거한다('['와 숫자)
            numbers[start] = '['; // ','를 '['로 바꾼다
        }
        else if (numbers[start + 3] == ',') // 두 자리 숫자일 때
        {
            start += 3;           // 앞에 것을 제거한다('['와 숫자)
            numbers[start] = '['; // ','를 '['로 바꾼다
        }
        else if (numbers[start + 4] == ',') // 세 자리 숫자일 때
        {
            start += 4;           // 앞에 것을 제거한다('['와 숫자)
            numbers[start] = '['; // ','를 '['로 바꾼다
        }
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
            if (n == 0) // 숫자가 없는데 숫자를 빼려고 하면 에러
            {
                printf("error\n");
                return;
            }
            D(flag, orders, numbers);
            n--;
        }
    }

    if (flag) // 거꾸로 출력해야 할 때
    {
        int i = end - 2;  // 괄호는 출력하지 않고 바로 숫자로 인덱스 이동
        printf("[");      // 여는 괄호 먼저 출력
        while (i > start) // 괄호가 나오기 전까지만
        {
            if (numbers[i] == ',') // 쉼표는 바로 출력
            {
                printf("%c", numbers[i]);
                i--;
            }
            else // 숫자일 때(대괄호는 끝나는 숫자를 위하여 조건 추가)
            {
                if (numbers[i - 1] == ',' || numbers[i - 1] == '[') // 한 자리일 때
                {
                    printf("%c", numbers[i]);
                    i--;
                }
                else if (numbers[i - 2] == ',' || numbers[i - 2] == '[') // 두 자리일 때
                {
                    printf("%c%c", numbers[i - 1], numbers[i]);
                    i -= 2;
                }
                else if (numbers[i - 3] == ',' || numbers[i - 3] == '[') // 세 자리 일때
                {
                    printf("%c%c%C", numbers[i - 2], numbers[i - 1], numbers[i]);
                    i -= 3;
                }
            }
        }
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
        char numbers[100000000] = {0};
        char orders[100000000] = {0};
        scanf("%s", orders);
        scanf("%d", &n);
        scanf("%s", numbers);

        AC(n, orders, numbers);
    }
    return 0;
}