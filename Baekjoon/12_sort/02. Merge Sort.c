#include <stdio.h>

void merge(int a[], int low, int mid, int high) // �и��� �迭 ���� �� ���� �Լ�
{
    int b[1000000];
    int i = low;     // ���� �迭 ���� �ε���
    int j = mid + 1; // ������ �迭 ���� �ε���
    int k = 0;       // �迭 b�� �ε���

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])    // ���� �迭 ���� ������ �迭 ������ ũ��
            b[k++] = a[i++]; // ���� k�� i���� �־� ���� ��, k++, i++ ���ִ� ��
        else                 // ������ �迭 ���� ���� �迭 ������ ũ��
            b[k++] = a[j++];
    }

    while (i <= mid) // ���� �迭�� �����ִٸ�
        b[k++] = a[i++];

    while (j <= high) // ������ �迭�� �����ִٸ�
        b[k++] = a[j++];

    k--; // �������� ���߱⿡ �ϳ� ���ش�

    while (k >= 0) // �迭 b ������ �迭 a�� ����(�ڿ������� ����)
    {
        a[low + k] = b[k];
        k--;
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high) // �迭�� ���̰� 2 �̻��� ��
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main(void)
{
    int num;
    scanf("%d", &num);

    int number[1000000];
    for (int i = 0; i < num; i++)
        scanf("%d", &number[i]);

    mergeSort(number, 0, num - 1);

    for (int i = 0; i < num; i++)
        printf("%d\n", number[i]);

    return 0;
}