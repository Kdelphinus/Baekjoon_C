#include <stdio.h>
#define _USE_MATH_DEFINES // ��Ȯ�� ���̰��� �������� ���Ͽ�
#include <math.h>

int main()
{
    int radius;
    float taxi_radius;
    scanf("%d", &radius);

    // ��Ŭ���� ������
    printf("%.6f\n", radius * radius * M_PI);

    // �ý� ������
    printf("%.6f\n", radius * radius * 2.0);

    return 0;
}