#include <stdio.h>

int main()
{
    int num1 = 2;
    int num2 = 2;

    printf("%d %d\n", num1++, num2--); // 2 2: num1, num2의 값을 먼저 출력한 뒤 증감 연산자 동작
    printf("%d %d\n", num1, num2);     // 3 1: 증감 연산자가 동작한 결과

    printf("\n");

    int num3 = 2;
    int num4 = 2;

    printf("%d %d\n", ++num3, --num4); // 3 1: 증감 연산자가 먼저 동작한 뒤 num3, num4의 값을 출력
    printf("%d %d\n", num3, num4);     // 3 1: 앞과 같은 값이 출력됨

    return 0;
}