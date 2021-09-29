#include <stdio.h>
#include <string.h>

int main()
{
    int test, repeat, size_str, size_p, k = 0;
    char str[20];
    char *str_ptr;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        scanf("%d %s", &repeat, str);
        str_ptr = &str[0];

        size_str = strlen(str);
        size_p = size_str * repeat;
        char p[size_p];

        for (int j = 0; j < size_str; j++)
        {
            for (int h = k; h < repeat + k; h++)
            {
                p[h] = *(str_ptr + j);
            }
            k += repeat;
        }
        // printf("%s\n", p);
        for (int j = 0; j < size_p; j++)
        {
            printf("%c", p[j]);
        }

        printf("\n");

        k = 0;
    }

    return 0;
}