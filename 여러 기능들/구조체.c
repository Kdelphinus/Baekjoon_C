// // 구조체: 다른 타입의 변수를 하나로 묶은 형태
// struct tag_name
// {
//     data
// } 구조체 변수 목록;

#include <stdio.h>

int main()
{
    struct Point
    {
        int x, y;
    } pt;

    pt.x = 100;
    pt.y = 50;

    printf("pt.x = %d / pt.y = %d\n", pt.x, pt.y);
    printf("pt.x = %d / pt.y = %d", pt); // 동일한 결과
    return 0;
}
