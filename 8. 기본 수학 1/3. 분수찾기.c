#include <stdio.h>

int main()
{
    int num, cnt = 1, den = 1, nume = 1; // denominator: �и�, numerator: ����
    scanf("%d", &num);

    while (cnt != num)
    {
        // �и� + ���ڰ� ¦���� ��
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

        // �и� + ���ڰ� Ȧ���� ��
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