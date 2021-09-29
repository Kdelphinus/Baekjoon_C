#include <stdio.h>

int num, sum, min = 1000000000, max = -1000000000;
int number[101]; // 숫자를 저장할 배열
int operator[4]; // 연산자의 개수를 저장할 배열

int DFS(int l)
{
    if (l == num - 1) // 연산자 조합을 다 했다면
    {
        if (min > sum) // 최솟값
            min = sum;
        if (max < sum) // 최댓값
            max = sum;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (l == 0) // 받은 개수만큼만 사용
                sum = number[l];
            if (operator[i]> 0) // 연산자가 아직 남아있으면
            {
                int tmp = sum; // 원본을 저장하고
                if (i == 0)    // +
                    sum += number[l + 1];
                else if (i == 1) // -
                    sum -= number[l + 1];
                else if (i == 2) // *
                    sum *= number[l + 1];
                else // /
                    sum /= number[l + 1];
                operator[i]--; // 사용한 연산자의 개수를 차감
                DFS(l + 1);    // 다음 위치 연산자로 이동
                operator[i]++; // 돌아온 연산자 추가
                sum = tmp;     // 연산 전 결과값으로 변경
            }
        }
    }
}

int main()
{
    scanf("%d", &num); // 숫자의 개수

    for (int i = 0; i < num; i++) // 숫자를 받음
        scanf("%d", &number[i]);

    for (int i = 0; i < 4; i++) // 연산자의 개수들을 받음
        scanf("%d", &operator[i]);

    DFS(0);

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}