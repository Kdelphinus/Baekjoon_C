#include <stdio.h>
#include <stdlib.h>

int cnt;
int n_arr[500001];

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 > num2)
        return 1;
    if (num1 < num2)
        return -1;
    return 0;
}

void binary_search(int start, int end, int num)
{
    if (start > end)
        return;

    int mid = (start + end) / 2;

    if (n_arr[mid] < num)
    {
        binary_search(mid + 1, end, num);
        return;
    }
    else if (n_arr[mid] > num)
    {
        binary_search(start, mid, num);
        return;
    }
    else
    {
        cnt++;
        binary_search(start, mid, num), binary_search(mid + 1, end, num);
        return;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &n_arr[i]);

    int m;
    scanf("%d", &m);
    int m_arr[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &m_arr[i]);

    qsort(n_arr, n, sizeof(int), compare);

    for (int i = 0; i < m; i++)
    {
        binary_search(0, n - 1, m_arr[i]);
        printf("%d ", cnt);
        cnt = 0;
    }

    return 0;
}