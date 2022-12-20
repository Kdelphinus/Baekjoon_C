#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char arr[])
{
    int len = strlen(arr);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

int main()
{
    int num1_size, num2_size, tem = 0, i = 0;
    char num1[100000], num2[100000], num[100000];

    scanf("%s %s", num1, num2);

    num1_size = strlen(num1) - 1;
    num2_size = strlen(num2) - 1;

    while (1)
    {
        if (num1_size >= 0 && num2_size >= 0)
        {
            tem += (num1[num1_size] - '0') + (num2[num2_size] - '0');
            num[i] = tem % 10 + '0';
            tem /= 10;
        }
        else if (num1_size >= 0 && num2_size < 0)
        {
            if (tem > 0)
            {
                tem += (num1[num1_size] - '0');
                num[i] = tem % 10 + '0';
                tem /= 10;
            }
            else
                num[i] = num1[num1_size];
        }
        else if (num1_size < 0 && num2_size >= 0)
        {
            if (tem > 0)
            {
                tem += (num2[num2_size] - '0');
                num[i] = tem % 10 + '0';
                tem /= 10;
            }
            else
                num[i] = num2[num2_size];
        }

        num1_size--;
        num2_size--;
        i++;

        if (num1_size < 0 && num2_size < 0)
        {
            if (tem > 0)
                num[i] = tem + '0';
            break;
        }
    }

    reverse(num);
    printf("%s", num);

    return 0;
}