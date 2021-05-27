#include <stdio.h>

void merge(int a[], int low, int mid, int high) // 분리된 배열 정렬 및 병합 함수
{
    int b[1000000];
    int i = low;     // 왼쪽 배열 시작 인덱스
    int j = mid + 1; // 오른쪽 배열 시작 인덱스
    int k = 0;       // 배열 b의 인덱스

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])    // 왼쪽 배열 값이 오른쪽 배열 값보다 크면
            b[k++] = a[i++]; // 원래 k와 i값을 넣어 구한 뒤, k++, i++ 해주는 것
        else                 // 오른쪽 배열 값이 왼쪽 배열 값보다 크면
            b[k++] = a[j++];
    }

    while (i <= mid) // 왼쪽 배열이 남아있다면
        b[k++] = a[i++];

    while (j <= high) // 오른쪽 배열이 남아있다면
        b[k++] = a[j++];

    k--; // 마지막도 더했기에 하나 빼준다

    while (k >= 0) // 배열 b 내용을 배열 a에 복사(뒤에서부터 복사)
    {
        a[low + k] = b[k];
        k--;
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high) // 배열의 길이가 2 이상일 때
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