/**
 * @file 02. Room assignment.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-16 21:12:11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start;
    int end;
} point;

point sort[100001];

int merge(point *time, int start, int mid, int end)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = start;

    while (i <= mid && j <= end)
    {
        if (time[i].start < time[j].start)
            sort[k++] = time[i++];
        else if (time[i].start > time[j].start)
            sort[k++] = time[j++];
        else
        {
            if (time[i].end < time[j].end)
                sort[k++] = time[i++];
            else if (time[i].end > time[j].end)
                sort[k++] = time[j++];
            else
            {
                sort[k++] = time[i++];
                sort[k++] = time[j++];
            }
        }
    }

    if (i <= mid)
    {
        while (i <= mid)
            sort[k++] = time[i++];
    }

    if (j <= end)
    {
        while (j <= end)
            sort[k++] = time[j++];
    }

    for (int k = start; k <= end; k++)
        time[k] = sort[k];
}

int mergeSort(point *time, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergeSort(time, start, mid);
        mergeSort(time, mid + 1, end);
        merge(time, start, mid, end);
    }
}

int meeting_room(point *time, int num)
{
    int prev = 0, cnt = 1; // ���� ���� �ε���, ���� ��

    for (int i = 1; i < num; i++)
    {
        if (time[i].end < time[prev].end)         // �� ���ú��� ���� ������ �� ����������
            prev = i;                             // �� ������ ���� ���� ������ �־��ش�
        else if (time[i].start >= time[prev].end) // ���� ���� ���� �ð��� �� ���� ������ �ð��� ���ų� ���ĸ�
        {                                         //
            cnt++;                                // ���� ���� �߰��ϰ�
            prev = i;                             // ���� ������ �� �������� �ٲ۴�
        }
    }

    return cnt;
}

int main()
{
    int num;
    scanf("%d", &num);

    point *time = (point *)malloc(sizeof(point) * num);
    for (int i = 0; i < num; i++)
        scanf("%d %d", &time[i].start, &time[i].end);

    mergeSort(time, 0, num - 1); // ����

    printf("%d", meeting_room(time, num));
    return 0;
}