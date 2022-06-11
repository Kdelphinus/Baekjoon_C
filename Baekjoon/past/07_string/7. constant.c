#include <stdio.h>

int main()
{
    int input1, input2, num1 = 0, num2 = 0, tem = 100;
    scanf("%d %d", &input1, &input2);

    // input1 뒤집기
    while (input1 != 0)
    {
        num1 += (input1 % 10) * tem;
        input1 /= 10;
        tem /= 10;
    }

    // tem 초기화
    tem = 100;

    // input2 뒤집기
    while (input2 > 0)
    {
        num2 += (input2 % 10) * tem;
        input2 /= 10;
        tem /= 10;
    }

    if (num1 > num2)
    {
        printf("%d\n", num1);
    }
    else if (num1 < num2)
    {
        printf("%d\n", num2);
    }

    return 0;
}