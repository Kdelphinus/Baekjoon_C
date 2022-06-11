#include <stdio.h>
#include <math.h>
#define size 1000000

int start[size];
int end[size];

int hanoi(int num, int start, int end) // ���� ����, ���� ��ġ, ������ġ
{
    int other = 6 - start - end; // ������ ��ġ

    if (num == 1) // ������ �ϳ��̸� ����������� ������������ �̵��ϰ� ����
    {
        printf("%d %d\n", start, end);
        return 0;
    }

    hanoi(num - 1, start, other);  // ���� ū ������ ���� ������ ������ ������ ������ ��� �ٸ� ��ġ�� �̵��ؾ� �Ѵ�
    printf("%d %d\n", start, end); // ���� ū ���� �̵�
    hanoi(num - 1, other, end);    // ������ ���ǵ� ������ġ�� �̵�
    return 0;
}

int main()
{

    int num, cnt;
    scanf("%d", &num);

    cnt = pow(2, num) - 1;
    printf("%d\n", cnt);
    hanoi(num, 1, 3);

    return 0;
}