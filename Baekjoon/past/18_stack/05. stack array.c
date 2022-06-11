/**
 * @file practice.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 모범답안 출처: https://wtg-study.tistory.com/53
 * @date 2021-06-28 22:45:49
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#define SIZE 1000000
int arr[SIZE];
int stack[SIZE];
char result[SIZE * 2];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int num = 1, top = -1;
    int idx = 0, result_idx = 0;
    while (1)
    {
        if (top == -1 || stack[top] < arr[idx]) // 스택에 있는 수가 목표수보다 낮은 경우
        {
            stack[++top] = num++;       // 스택에 숫자를 집어넣고
            result[result_idx++] = '+'; // push 로그
        }
        else if (stack[top] == arr[idx]) // 스택에 있는 수가 목표수인 경우
        {
            top--;                      // 스택에 있는 수를 빼고(인덱스만 옮긴 뒤 나중에 덮어쓰기 식으로)
            result[result_idx++] = '-'; // pop 로그
            idx++;                      // 목표수가 들은 배열의 인덱스 이동
        }
        else // 스택의 마지막 수가 목표수보다 크면 원하는 수열을 만들 수 없다
        {
            printf("NO\n"); // 불가능을 출력하고
            return 0;       // main함수를 종료
        }

        if (result_idx == 2 * n)
            break;
    }

    for (int i = 0; i < result_idx; i++)
        printf("%c\n", result[i]);

    return 0;
}