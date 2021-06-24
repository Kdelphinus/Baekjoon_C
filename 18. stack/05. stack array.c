#include <stdio.h>

int number[100001], anwser[100001];
int in = 1;

void push(int num)
{
    number[in++] = num;
    printf("+\n");
}

void pop()
{
    in--;
    number[in] = 0;
    printf("-\n");
}

void stack_array(int num)
{
    int tmp, n = 1, k = 0;
    for (int i = 1; i <= num; i++)
    {
        if (anwser[i] == num)
            tmp = i;
    }

    for (int i = tmp; i < num; i++)
    {
        if (anwser[i] < anwser[i + 1])
        {
            printf("NO");
            return;
        }
    }

    while (1)
    {
        if (anwser[k] == n)
        {
            push(n);
            pop();
            k++;
        }
        else
        {
            push(n);
        }

        if (anwser[k] == number[in])
        {
            pop();
            k++;
        }

        if (n < num)
            n++;

        if (number[0] == 0 && n == num)
            break;
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
        scanf("%d", &anwser[i]);

    stack_array(num);

    return 0;
}