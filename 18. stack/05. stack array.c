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
    // i: 오름차순 된 숫자리스트(number)의 인덱스
    // j: 원하는 배열(sol)의 인덱스
    // k: 스택의 인덱스
    // l: 명령이 저장된 배열(anw)의 인덱스
    // number: 숫자가 오름차순으로 저장된 배열
    // anw: 명령이 저장된 배열
    // stack: 스택 역할을 할 배열
    int i = 0, j = 0, k = 0, l = 0, number[num];

    for (int b = 1; b <= num; b++) // 숫자를 오름차순으로 저장
        number[b - 1] = b;

    while (1)
    {
        if ((sol[j] != stack[k - 1] && k - 1 >= 0) || strlen(stack) == 0) // 현재 스택 끝 숫자와 원하는 배열의 숫자가 불일치하거나 스택에 숫자가 없는 경우
        {
            if (i == num) // 근데 이미 number를 다 돌았다면
            {
                printf("NO"); // 불가능
                break;
            }
            stack[k++] = number[i++]; // 스택에 현재 number의 숫자를 추가
            anw[l++] = '+';           // push 명령어 추가
        }
        else // 만약 현재 스택 끝 숫자와 원하는 배열의 숫자가 일치하면
        {
            anw[l++] = '-';  // pop 명령어 추가
            k--;             // 스택의 인덱스를 하나 줄이고
            stack[k] = '\0'; // 스택 마지막 숫자를 뺀다
            j++;             // 원하는 배열의 인덱스를 하나 늘린다
        }

        if (j == num) // 원하는 배열을 끝까지 다 돌았을 때
        {
            if (strlen(stack) == 0) // 스택이 비어있다면
            {
                int size;
                size = strlen(anw);
                for (int a = 0; a < size; a++) // 명령어를 출력하고
                    printf("%c\n", anw[a]);
                break;
            }
            else // 남아있다면
            {
                printf("NO"); // 불가능하다
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