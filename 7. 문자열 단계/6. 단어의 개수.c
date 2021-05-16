#include <stdio.h>
#include <string.h>

int main()
{
    char sen[1000000];
    char *sen_ptr;
    int cnt = 0;

    scanf("%[^\n]s", sen);

    sen_ptr = strtok(sen, " ");

    while (sen_ptr != NULL)
    {
        sen_ptr = strtok(NULL, " ");
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}