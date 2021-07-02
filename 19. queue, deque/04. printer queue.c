/**
 * @file 04. printer queue.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 배열 오류로 오답처리가 되나 아직 문제점을 찾지 못함
 * @date 2021-07-02 23:26:48
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int importance[100000001][2]; // [중요도, 인덱스]로 저장한 배열
int tmp_arr[101];             // 중요도만 저장하여 내림차순한 배열(현재 뽑을 문서의 중요도가 맨 앞에 있다)

int compare(const void *a, const void *b) // 정렬을 위한 함수
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return 1;
    if (num2 < num1)
        return -1;
    return 0;
}

int printer(int num, int order)
{
    int start = 0, end = 0, tmp_idx = 0; // 시작 인덱스, 끝 인덱스, 내림차순한 배열의 인덱스
    int check = 0;                       // 문서를 몇번째로 뽑았는지 저장할 변수
    end = num;                           // 초기 끝 인덱스는 문서의 개수와 동일

    while (1)
    {
        if ((tmp_arr[tmp_idx] == importance[start][0]) && (order == importance[start][1])) // 현재 뽑아야 하고 알고 싶은 문서라면
            return check + 1;                                                              // 현재 뽑는 수까지 포함하여 리턴

        if (tmp_arr[tmp_idx] == importance[start][0]) // 현재 뽑아야 할 문서지만 알고 싶은 문서가 아니라면
        {
            check++;   // 뽑은 횟수 추가
            tmp_idx++; // 다음 중요도 문서로 이동
            start++;   // 맨 앞 문서를 뽑아버림
        }
        else // 문서를 뽑을 때가 아니면
        {
            // 문서를 맨 뒤로 옮긴다
            importance[end][0] = importance[start][0];
            importance[end][1] = importance[start][1];
            start++;
            end++;
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int num, order;
        scanf("%d %d", &num, &order);

        for (int j = 0; j < num; j++)
        {
            // 문서의 중요도와 인덱스 저장
            scanf("%d", &importance[j][0]);
            importance[j][1] = j;

            // 문서의 중요도만 저장
            tmp_arr[j] = importance[j][0];
        }

        // 문서의 중요도만 저장한 배열을 내림차순
        qsort(tmp_arr, sizeof(tmp_arr) / sizeof(int), sizeof(int), compare);

        printf("%d\n", printer(num, order));
    }

    return 0;
}