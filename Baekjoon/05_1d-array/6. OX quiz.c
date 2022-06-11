#include <stdio.h>

int main()
{

    int test, check = 0, score = 0;
    scanf("%d", &test);

    char anw[80];
    char *anw_ptr;

    anw_ptr = &anw[0];

    for (int j = 0; j < test; j++)
    {
        scanf("%s", &anw);
        for (int i = 0; i < 80; i++)
        {
            if (*(anw_ptr + i) == 'O')
            {
                check++;
                score += check;
            }
            else
            {
                check = 0;
            }
        }
        printf("%d\n", score);
        score = 0;

        for (int i = 0; i < 80; i++)
        {
            anw[i] = 'X';
        }
    }

    return 0;
}