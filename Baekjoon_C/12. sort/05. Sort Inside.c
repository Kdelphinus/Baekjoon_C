#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    int num1 = *(char *)a;
    int num2 = *(char *)b;

    if (num1 < num2)
        return 1;

    if (num1 > num2)
        return -1;

    return 0;
}

int main()
{
    char num[11]; // 숫자 길이가 최대 10개이므로
    int len;

    scanf("%s", num);
    len = strlen(num); // 받은 숫자의 길이

    int number[len];
    for (int i = 0; i < len; i++) // 숫자 리스트로 변환
        number[i] = num[i] - '0';

    qsort(number, len, sizeof(int), compare); // 내림차순 정렬

    for (int i = 0; i < len; i++)
        printf("%d", number[i]);

    return 0;
}