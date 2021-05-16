#include <stdio.h>

int main()
{
    int test, num;
    float rate, avg, cnt = 0.0, sum = 0.0;
    scanf("%d", &test);
    // printf("test: %d\n", test);

    for (int i = 0; i < test; i++)
    {
        // 학생 수를 받음
        scanf("%d", &num);
        int score[num];
        // printf("num: %d\n", num);

        // 점수를 받고 받을 때마다 더하여 합을 만듬
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &score[j]);
            sum += score[j];
            // printf("sum %d: %fl\n", j, sum);
        }

        // 평균을 구함
        avg = sum / num;
        // printf("avg: %fl\n", avg);

        // 평균 이상인 학생의 수를 구함
        for (int j = 0; j < num; j++)
        {
            if (avg < score[j])
                cnt++;
            // printf("cnt: %fl\n", cnt);
        }

        // 비율을 구하고 출력
        rate = 100 * cnt / num;
        printf("%.3f%%\n", rate);

        // 초기화
        cnt = 0;
        sum = 0.0;
    }

    return 0;
}