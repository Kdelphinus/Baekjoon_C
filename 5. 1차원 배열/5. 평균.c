#include <stdio.h>

int main()
{
    double new_score, avg, new_scores = 0.0;
    int count, input, max = 0;
    scanf("%d", &count);

    int score[count];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &input);
        score[i] = input;
        if (max < input)
            max = input;
    }
    printf("%d\n", max);

    for (int i = 0; i < count; i++)
    {
        new_score = (double)(100.0 * score[i] / max);
        new_scores += new_score;
    }
    avg = new_scores / count;
    printf("\n%lf", avg);

    // 소수점 둘째 자리까지 출력
    // printf("\n%.2f", avg);

    return 0;
}