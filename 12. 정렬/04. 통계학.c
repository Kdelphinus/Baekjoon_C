#include <stdio.h>
#include <math.h>   // floor 함수
#include <stdlib.h> // qsort 함수

int compare(const void *a, const void *b) // 오름차순을 위한 함수
{
    int num1 = *(int *)a; // void 포인터를 int 포인터로 변환한 뒤, 역 참조하여 값을 가져옴
    int num2 = *(int *)b; // void 포인터를 int 포인터로 변환한 뒤, 역 참조하여 값을 가져옴

    if (num1 < num2) // a < b일 땐 -1 반환
        return -1;

    if (num1 > num2) // a > b일 땐 1 반환
        return 1;

    return 0; // a = b일 땐 0 반환
}

int main()
{
    int num, mean, median, mode_cnt = 0, mode, repeat = 0;
    int check[8001] = {
        0,
    };
    double sum = 0.0;

    // 숫자 받고 배열 생성
    scanf("%d", &num);

    int numbers[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // c에 내장된 퀵 정렬
    // 정렬할 배열, 요소 개수(sizeof(numbers) / sizeof(int)), 요소 크기, 비교 함수
    qsort(numbers, num, sizeof(int), compare);

    // 산술 평균
    for (int i = 0; i < num; i++)
    {
        sum += numbers[i];
    }
    mean = floor(sum / num + 0.5); // floor은 내림함수, 0.5를 더하여 내리면 반올림과 같은 결과가 나온다
    printf("%d\n", mean);

    // 중앙값
    median = num / 2;
    printf("%d\n", numbers[median]);

    // 최빈값
    for (int i = 0; i < num; i++)
    {
        check[4000 + numbers[i]] += 1; // -4000 ~ 4000를 0 ~ 8000에 순서대로 넣기 위하여
    }

    for (int i = 0; i < 8001; i++)
    {
        if (mode_cnt < check[i]) // 빈도수가 더 큰 숫자를 찾았을 때
        {
            mode = i - 4000;
            mode_cnt = check[i];
            repeat = 1;
        }
        else if (mode_cnt == check[i] && repeat == 1) // 최댓값과 같은 수를 또 찾았을 때, 그 수가 두 번째로 나온 똑같은 수라면
        {
            mode = i - 4000;
            mode_cnt = check[i];
            repeat++;
        }
    }

    printf("%d\n", mode);

    // 범위
    printf("%d\n", numbers[num - 1] - numbers[0]);

    return 0;
}