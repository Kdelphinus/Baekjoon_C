/**
 * @file 01. multiples and divisors.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-21 15:57:52
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int main()
{
    while (1)
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);

        if (num1 == 0 && num2 == 0)
            break;

        if (num1 < num2 && num2 % num1 == 0)
            printf("factor\n");
        else if (num1 > num2 && num1 % num2 == 0)
            printf("multiple\n");
        else
            printf("neither\n");
    }

    return 0;
}