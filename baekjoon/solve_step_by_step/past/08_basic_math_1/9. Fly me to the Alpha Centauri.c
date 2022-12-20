#include <stdio.h>
#include <math.h>

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int start, end, len, cnt = 0, num, limit;
        scanf("%d %d", &start, &end);

        // 가야할 거리
        len = end - start;

        // 4보다 작으면 1씩만 이동가능
        if (len < 4)
            printf("%d\n", len);

        /* len이 (num + 1) * (num + 1)미만이면 한 번에 최대 num까지만 이동 가능 */
        /* 또한 양 끝은 1,2...num-1으로 제한됨 */
        else
        {
            num = (int)sqrt(len);
            limit = num * (num - 1);

            len -= limit;

            // 제한된 방법에서 변경하는 횟수 + 사이에 들어갈 수 있는 횟수
            cnt = 2 * (num - 1) + len / num;

            if (len % num == 0)
                printf("%d\n", cnt);
            else // 나머지가 있을 때, 그것은 num보다 작기에 한 번만 더 이동하면 된다
                printf("%d\n", cnt + 1);
        }
    }
    return 0;
}