#include <stdio.h>

int N, cnt;             // N x N ü����
int height[15];         // ����
int left_diagonal[30];  // ���ʹ������� �������� �밢��
int right_diagonal[30]; // �����ʹ������� �������� �밢��

void N_Queen(int i)
{
    if (N == i) // ���� ������ �ξ��� ��
        cnt++;
    else
    {
        for (int j = 0; j < N; j++)
        {
            if (height[j] == 0 && left_diagonal[i + j] == 0 && right_diagonal[i - j + N - 1] == 0)
            { // ����, ���� �밢��, ������ �밢���� ���� ���� ��

                // �� ��ġ�� �������� ����, ���� �밢��, ������ �밢���� ��ġ�� ǥ��
                height[j] = 1;
                left_diagonal[i + j] = 1;
                right_diagonal[i - j + N - 1] = 1;

                N_Queen(i + 1); // ���� ������ �̵�

                // ���� �ǵ���
                height[j] = 0;
                left_diagonal[i + j] = 0;
                right_diagonal[i - j + N - 1] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d", &N); // ü������ ũ�⸦ ����
    N_Queen(0);      // ù��° ����� ����
    printf("%d", cnt);
    return 0;
}