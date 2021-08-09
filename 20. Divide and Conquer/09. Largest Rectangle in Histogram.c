/**
 * @file 09. Largest Rectangle in Histogram.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief https://hackids.tistory.com/59 해설참고, 문제는 다르나 풀이는 같음
 * @date 2021-08-09 19:29:22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

long long hist[100001];

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}

long long min(long long a, long long b)
{
    if (a > b)
        return b;
    return a;
}

long long largest_rectangle(int start, int end)
{
    if (start == end) // 범위가 직사각형 하나면 직사각형 넓이가 바로 최대값이다
        return hist[start];

    int mid = (start + end) / 2;
    int start_point = mid;
    int end_point = mid;
    long long height = hist[mid];
    long long ret = max(largest_rectangle(start, mid), largest_rectangle(mid + 1, end)); // 범위를 절반씩 나눠가며 가능한 직사각형의 최대 넓이를 구한다

    while (start < start_point || end_point < end)
    {
        // 아직 시작 범위까지 탐색하지 않았고 끝지점에 도달했거나 현재 탐색하는 시작 범위 이전 넓이가 현재 탐색하는 이후 넓이보다 크다면
        if (start < start_point && (end_point == end || hist[start_point - 1] > hist[end_point + 1]))
        {
            start_point--;                           // 탐색하는 시작 범위를 앞으로 당기고
            height = min(height, hist[start_point]); // 새로 생긴 시작 범위의 사각형과 현재 높이 중 작은 것을 가져간다
        }
        // 아닐 경우엔
        else
        {
            end_point++;                           // 끝 범위를 뒤로 하나 미루고
            height = min(height, hist[end_point]); // 새로 생긴 끝 범위의 사각형과 현재 높이 중 작은 것을 가져간다
        }
        ret = max(ret, height * (end_point - start_point + 1)); // 사각형 넓이 최신화
    }

    return ret;
}

int main()
{
    while (1)
    {
        int num;
        scanf("%d", &num);

        if (num == 0)
            break;

        for (int i = 0; i < num; i++)
            scanf("%lld", &hist[i]);

        printf("%lld\n", largest_rectangle(0, num - 1));
    }
    return 0;
}