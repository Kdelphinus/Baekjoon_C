/**
 * @file 10. Fashion king.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-23 17:43:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) // 문자열 내림차순 정렬(빈 공간들이 존재하기에)
{
    return -strcmp((char *)a, (char *)b);
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int num;
        scanf("%d", &num);
        int k = 0, kind_num[31] = {0}, cnt = 1, anw = 1; // 옷 종류, 같은 종류가 몇개 들어있는지 저장할 리스트, 같은 종류를 세는 변수, 경우의 수
        char name[31][21], kind[31][21] = {0};           // 이름을 저장할 배열, 옷의 종류를 저장할 배열(초기화시킴)

        for (int j = 0; j < num; j++)
            scanf("%s %s", name[j], kind[j]);

        qsort(kind, sizeof(kind) / sizeof(kind[0]), sizeof(kind[0]), compare); // 옷의 종류별로 내림차순(null문자도 있기에 내림차순으로 입력된 문자들이 먼저 보이게 함)

        for (int j = 1; j < num; j++)
        {
            if (strcmp(kind[j], kind[j - 1]) == 0) // 종류가 같으면 개수를 추가하고
                cnt++;
            else // 종류가 다르다면
            {
                kind_num[k++] = cnt; // 지금까지 구한 종류 개수를 저장하고 인덱스 이동
                cnt = 1;             // 옷의 종류 수 초기화
            }
        }
        if (num > 0)
            kind_num[k++] = cnt; // 마지막 옷의 종류 수도 저장

        for (int j = 0; j < k; j++) // 옷을 벗는 경우의 수까지 구하기위해 +1을 하여 곱함
            anw *= kind_num[j] + 1;

        printf("%d\n", anw - 1); // 다 벗는 상황을 빼기 위해서 -1을 함
    }
    return 0;
}