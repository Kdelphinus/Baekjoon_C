#include <stdio.h>

int main()
{
    int test, num;
    float rate, avg, cnt = 0.0, sum = 0.0;
    scanf("%d", &test);
    // printf("test: %d\n", test);

    for (int i = 0; i < test; i++)
    {
        // �л� ���� ����
        scanf("%d", &num);
        int score[num];
        // printf("num: %d\n", num);

        // ������ �ް� ���� ������ ���Ͽ� ���� ����
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &score[j]);
            sum += score[j];
            // printf("sum %d: %fl\n", j, sum);
        }

        // ����� ����
        avg = sum / num;
        // printf("avg: %fl\n", avg);

        // ��� �̻��� �л��� ���� ����
        for (int j = 0; j < num; j++)
        {
            if (avg < score[j])
                cnt++;
            // printf("cnt: %fl\n", cnt);
        }

        // ������ ���ϰ� ���
        rate = 100 * cnt / num;
        printf("%.3f%%\n", rate);

        // �ʱ�ȭ
        cnt = 0;
        sum = 0.0;
    }

    return 0;
}