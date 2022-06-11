/**
 * @file 09. Largest Rectangle in Histogram.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief https://hackids.tistory.com/59 �ؼ�����, ������ �ٸ��� Ǯ�̴� ����
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
    if (start == end) // ������ ���簢�� �ϳ��� ���簢�� ���̰� �ٷ� �ִ밪�̴�
        return hist[start];

    int mid = (start + end) / 2;
    int start_point = mid;
    int end_point = mid;
    long long height = hist[mid];
    long long ret = max(largest_rectangle(start, mid), largest_rectangle(mid + 1, end)); // ������ ���ݾ� �������� ������ ���簢���� �ִ� ���̸� ���Ѵ�

    while (start < start_point || end_point < end)
    {
        // ���� ���� �������� Ž������ �ʾҰ� �������� �����߰ų� ���� Ž���ϴ� ���� ���� ���� ���̰� ���� Ž���ϴ� ���� ���̺��� ũ�ٸ�
        if (start < start_point && (end_point == end || hist[start_point - 1] > hist[end_point + 1]))
        {
            start_point--;                           // Ž���ϴ� ���� ������ ������ ����
            height = min(height, hist[start_point]); // ���� ���� ���� ������ �簢���� ���� ���� �� ���� ���� ��������
        }
        // �ƴ� ��쿣
        else
        {
            end_point++;                           // �� ������ �ڷ� �ϳ� �̷��
            height = min(height, hist[end_point]); // ���� ���� �� ������ �簢���� ���� ���� �� ���� ���� ��������
        }
        ret = max(ret, height * (end_point - start_point + 1)); // �簢�� ���� �ֽ�ȭ
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