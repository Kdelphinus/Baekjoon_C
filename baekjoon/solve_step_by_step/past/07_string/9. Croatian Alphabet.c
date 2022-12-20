#include <stdio.h>
#include <string.h>

int main()
{
    int size, word_num;
    char str[101];
    scanf("%s", str);

    size = strlen(str);
    word_num = size;

    for (int i = 1; i < size; i++)
    {
        if (str[i] == '=' && (str[i - 1] == 'c' || str[i - 1] == 's'))
            word_num--;
        else if (str[i] == '-' && (str[i - 1] == 'c' || str[i - 1] == 'd'))
            word_num--;
        else if (str[i] == 'j' && (str[i - 1] == 'l' || str[i - 1] == 'n'))
            word_num--;
        else if (str[i] == '=' && str[i - 1] == 'z')
        {
            if (str[i - 2] == 'd' && i > 1)
                word_num -= 2;
            else
                word_num--;
        }
    }

    printf("%d", word_num);

    return 0;
}