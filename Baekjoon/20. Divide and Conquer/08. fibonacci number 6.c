/**
 * @file 08. fibonacci number 6.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-08-04 17:33:03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long mod = 1000000007;
long long a[2][2];
long long origin[2][2];

void matrix_multiplication() // a�� �����ϴ� �Լ�
{
    long long tmp[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int num = 0;
            for (int k = 0; k < 2; k++)
                num += (a[i][k] * a[k][j]) % mod;
            tmp[i][j] = num % mod;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            a[i][j] = tmp[i][j];
    }
}

void square_matrix(long long b)
{
    if (b == 1)
        return;

    if (b == 2)
        return matrix_multiplication();

    square_matrix(b / 2); // a^b�� ¦���� �� a^(b / 2) * a^(b / 2), Ȧ���� �� a^(b / 2) * a^(b / 2) * a�̴�
    matrix_multiplication();

    if (b % 2) // Ȧ���� ���ϸ� ������ �Լ��� �� ���� ���Ѵ�
    {
        long long tmp[2][2] = {0};

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int num = 0;
                for (int k = 0; k < 2; k++)
                    num += (a[i][k] * origin[k][j]) % mod;
                tmp[i][j] = num % mod;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                a[i][j] = tmp[i][j];
        }
    }
}

/*��� ������ �̿��Ͽ� �Ǻ���ġ ���� ���� �� �ִ�
[[F_n+1, F_n], [F_n, F_n-1]] = [[1, 1], [1, 0]] ** n*/
long long fib(long long num)
{
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;

    origin[0][0] = 1;
    origin[0][1] = 1;
    origin[1][0] = 1;

    if (num > 2)
        square_matrix(num - 1);

    return a[0][0] % mod;
}

int main()
{
    long long num;
    scanf("%lld", &num);
    printf("%lld", fib(num));
    return 0;
}