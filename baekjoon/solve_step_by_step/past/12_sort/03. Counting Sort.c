#include <stdio.h>

int main()
{
    int num, temp;
    int numbers[10001] = {
        0,
    };

    scanf("%d", &num);

    for (int i = 0; i < num; i++) // 숫자의 개수를 각 인덱스에 저장한다
    {
        scanf("%d", &temp);
        numbers[temp] += 1;
    }

    for (int i = 1; i < 10001; i++)
    {
        if (numbers[i] >= 1) // 만약 그 숫자가 있으면
        {
            for (int j = 0; j < numbers[i]; j++) // 들어간 숫자만큼 출력
                printf("%d\n", i);
        }
    }

    return 0;
}