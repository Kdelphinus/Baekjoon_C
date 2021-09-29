#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[] = "283";
    char s2[] = "253asdf698";
    int num1, num2;

    num1 = atoi(s1);      // 문자열을 정수형으로 변한
    printf("%d\n", num1); // 283

    num2 = atoi(s2);    // 문자가 섞인 문자열을 변환하면
    printf("%d", num2); //253, 문자가 나오기 전까지 숫자만 변환

    return 0;
}