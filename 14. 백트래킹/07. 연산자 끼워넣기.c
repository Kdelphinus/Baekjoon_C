#include <stdio.h>

int num, sum, min = 1000000000, max = -1000000000;
int number[101];   // 숫자를 저장할 배열
int operator[101]; // 연산자를 저장할 배열
int result[101];   // 연산자의 조합을 저장할 배열
int temp[4];       // 연산자의 개수를 저장할 배열
int check[4];      // 연산자 조합 중복을 방지하기 위한 배열

int DFS(int l)
{
    if (l == num - 1) // 연산자 조합을 다 했다면
    {
        sum = number[0]; // 첫 숫자로 시작
        for (int i = 1; i < num; i++)
        {
            if (result[i - 1] == 0) // +
                sum += number[i];
            else if (result[i - 1] == 1) // -
                sum -= number[i];
            else if (result[i - 1] == 2) // x
                sum *= number[i];
            else if (result[i - 1] == 3) // /
            {
                if (sum < 0)
                { // 음수를 양수로 나눌 때, 음수를 양수로 바꾸고 나눈 뒤, 몫을 음수로 바꿈
                    sum = -sum;
                    sum /= number[i];
                    sum = -sum;
                }
                else
                    sum /= number[i];
            }
        }
        if (min > sum) // 최솟값
            min = sum;
        if (max < sum) // 최댓값
            max = sum;
    }
    else
    {
        for (int i = 0; i < num - 1; i++)
        {
            if (check[operator[i]] < temp[operator[i]]) // 받은 개수만큼만 사용
            {
                check[operator[i]]++;
                result[l] = operator[i];
                DFS(l + 1);
                check[operator[i]]--;
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
        scanf("%d", &temp[i]);

    int oper, j = 0;
    for (int i = 0; i < 4; i++) // +: 0, -: 1, *: 2, /: 3
    {
        oper = i;

        for (int k = 0; k < temp[i]; k++) // 연산자 개수만큼 추가
            operator[j++] = oper;
    }
    DFS(0);

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}