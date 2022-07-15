/**
 * @file 06. NGE.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 풀이 출처: https://cocoon1787.tistory.com/347
 * @date 2021-07-01 21:28:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int stack[1000001]; // 스택
int anw[1000001];   // 오큰수를 넣을 배열

void NGE(int n, int arr[])
{
    int idx = 0; // 스택 인덱스

    for (int i = n - 1; i >= 0; i--) // 뒤에서부터 탐색 시작
    {
        while (idx > 0 && stack[idx - 1] <= arr[i]) // 스택이 없거나 현재 확인하는 수보다 스택에 있는 수가 큰 경우가 나올 때까지 스택의 수를 빼준다
            stack[--idx] = 0;

        if (idx == 0)                // 스택이 비어있다면
            anw[i] = -1;             // 오큰수가 없는 것이고
        else                         // 스택에 수가 있다면
            anw[i] = stack[idx - 1]; // 가장 위에 있는 수가 오큰수이다

        stack[idx++] = arr[i]; // 현재 숫자는 스택에 추가한다
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    NGE(n, arr);

    for (int i = 0; i < n; i++)
        printf("%d ", anw[i]);

    return 0;
}