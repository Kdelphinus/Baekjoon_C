/**
 * @file 11. Number of factorial 0.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 소인수분해 활용
 * @date 2021-06-23 19:11:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", num / 5 + num / 25 + num / 125); // 2의 배수는 많기에 5의 배수가 나오는 부분만 살핀다

    return 0;
}