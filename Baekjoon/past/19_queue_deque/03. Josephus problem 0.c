/**
 * @file 03. Josephus problem 0.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-02 19:46:14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int solution[1001];
int num[1000001];    // 1000개의 수를 1000번 뒤로 돌리는 것까지 되야 함
int start, end, idx; // 큐의 시작 인덱스, 끝 인덱스, solution 인덱스

int pop()
{
    int tmp;
    tmp = num[start++]; // 맨 앞의 수를 tmp에 저장하고 start에 1을 더함

    return tmp;
}

void back()
{
    num[end++] = num[start++]; //맨 앞의 숫자를 맨 뒤로 옮기고 start와 end에 1을 더함
}

void josephus(int n, int k)
{
    // 초기 설정
    end = n;
    for (int i = 0; i < n; i++)
        num[i] = i + 1;

    while (idx < n) // solution이 다 찰 때까지
    {
        int tmp;
        for (int i = 0; i < k - 1; i++) // k - 1번까진 숫자를 뒤로 넘기고
            back();

        solution[idx++] = pop(); // k번째 숫자를 빼서 solution에 넣는다
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    josephus(n, k);

    printf("<");
    for (int i = 0; i < idx; i++)
    {
        if (i == idx - 1)
            printf("%d>", solution[i]);
        else
            printf("%d, ", solution[i]);
    }

    return 0;
}