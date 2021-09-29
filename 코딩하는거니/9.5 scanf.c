#include <stdio.h>

int main()
{
    int box;
    printf("당신이 제일 좋아하는 숫자는 무엇입니까?");

    // &를 붙이는 이유는 변수의 값이 아니라 변수의 주소를 주어야 하기 때문
    scanf("%d", &box);
    printf("\n당신의 키는 %d 입니다.\n", box);

    char a[10];

    // 배열은 이미 첫번째 위치의 주소를 가리키기에 &를 안써줘도 된다
    scanf("문자 입력: %s", a);
    // scanf("%s", &a[0]); // 이런 표기도 가능
    printf("\n결과값: %s", a);

    return 0;
}