#include <stdio.h>
#define _USE_MATH_DEFINES // 정확한 파이값을 가져오기 위하여
#include <math.h>

int main()
{
    int radius;
    float taxi_radius;
    scanf("%d", &radius);

    // 유클리드 기하학
    printf("%.6f\n", radius * radius * M_PI);

    // 택시 기하학
    printf("%.6f\n", radius * radius * 2.0);

    return 0;
}