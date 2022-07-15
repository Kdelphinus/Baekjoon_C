#include <stdio.h>
#include <string.h>

int main()
{
    int size, time = 0;
    char word[15];
    scanf("%s", word);

    size = strlen(word);

    for (int i = 0; i < size; i++)
    {
        if (word[i] < 68)
            time += 3;
        else if (word[i] < 71)
            time += 4;
        else if (word[i] < 74)
            time += 5;
        else if (word[i] < 77)
            time += 6;
        else if (word[i] < 80)
            time += 7;
        else if (word[i] < 84)
            time += 8;
        else if (word[i] < 87)
            time += 9;
        else
            time += 10;
    }

    printf("%d", time);

    return 0;
}