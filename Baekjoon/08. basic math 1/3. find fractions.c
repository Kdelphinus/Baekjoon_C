#include <stdio.h>

int main()
{
    int num, cnt = 1, den = 1, nume = 1; // denominator: 분모, numerator: 분자
    scanf("%d", &num);

    while (cnt != num)
    {
        // 분모 + 분자가 짝수일 때
        if ((den + nume) % 2 == 0)
        {
            if (nume == 1)
                den++;
            else
            {
                nume--;
                den++;
            }
        }

        // 분모 + 분자가 홀수일 때
        else
        {
            if (den == 1)
                nume++;
            else
            {
                nume++;
                den--;
            }
        }

        cnt++;
    }

    printf("%d/%d", nume, den);

    return 0;
}