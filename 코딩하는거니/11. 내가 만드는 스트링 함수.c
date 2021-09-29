#include <stdio.h>
#include <string.h>

int myStrlen(char *arr)
{

    int counter = 0;
    char *cp = arr; // arr의 시작 지점

    while (*cp != '\0')
    {
        counter++;
        cp++;
    }
    return counter;
}

char *myStrcat(char *str1, char *str2)
{
    // 첫번째 스트링의 맨 뒤를 찾기
    int cnt = 0;
    while (*(str1 + cnt) != '\0')
    {
        cnt++;
    }

    // 첫번째 스트링의 끝 = 두번째 스트링 복사 시작
    int cnt2 = 0;
    while (*(str2 + cnt2) != '\0')
    {
        *(str1 + cnt + cnt2) = *(str2 + cnt2);
        cnt2++;
    }

    // 합쳐진 스트링 마지막에 '\0'을 추가
    *(str1 + cnt + cnt2) = '\0';

    return str1;
}

int myStrcmp(char *str1, char *str2)
{
    // 처음부터 차례대로 비교
    while (*str1 == *str2)
    {
        // '\0'이 나오면 멈춰라
        if (*str1 == '\0' || *str2 == '\0')
        {
            break;
        }
        str1++;
        str2++;
    }

    //
    if (*str1 == '\0' && *str2 == '\0')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char arr2[100] = "ABCDEFGHIJKLMNOP";
    char arr[100] = "abcdefghijklmnop";

    printf("srtlen: %d", strlen(arr));
    printf("\nmySrtlen: %d", myStrlen(arr));

    printf("\n%s", myStrcat(arr, arr2));

    printf("\n%d", myStrcmp(arr, arr2));

    return 0;
}