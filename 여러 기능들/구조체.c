// // ����ü: �ٸ� Ÿ���� ������ �ϳ��� ���� ����
// struct tag_name
// {
//     data
// } ����ü ���� ���;

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
    printf("pt.x = %d / pt.y = %d", pt); // ������ ���
    return 0;
}
