/**
 * @file 02. divisors.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-21 16:02:40
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;

    if (num1 > num2)
        return 1;

    return 0;
}

int main()
{
    int num;
    scanf("%d", &num);

    int divisors[num];
    for (int i = 0; i < num; i++)
        scanf("%d", &divisors[i]);

    qsort(divisors, sizeof(divisors) / sizeof(int), sizeof(int), compare);

    printf("%d", divisors[0] * divisors[num - 1]);

    return 0;
}