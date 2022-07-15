/**
 * @file 06. rotating queue.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief �迭 ũ�Ⱑ �� Ʋ������ ã�� ����
 * @date 2021-07-03 20:12:29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int deque[400]; // �� ����, �� 400������ ũ�Ⱑ �ʿ��Ѱ�?(102������ ������� �ʴ°�?)
int nums[90];   // �̾ƾ� �� ���ڸ� ���� �迭, �� 90������ ũ�Ⱑ �ʿ��Ѱ�?(51������ ������� �ʴ°�?)
int index[51];  // ���ڵ��� ����ִ� ���� �ε���(index[1]: ���� 1�� �� �ε����� ����Ǿ� ����)
int start = 51, end = 51;

void left_rotate() // �������� ����(�� ���� ���ڰ� �� �ڷ� ����)
{
    deque[end++] = deque[start++];
    index[deque[end - 1]] = end - 1;
}

void right_rotate() // ���������� ����(�� ���� ���ڰ� �� ������ �´�)
{
    deque[--start] = deque[--end];
    index[deque[start]] = start;
}

int rotating(int size, int num, int nums[])
{
    int idx = 0, cnt = 0; // ������ ���ڸ� ����Ű�� �ε���, ȸ�� Ƚ��

    for (int i = 1; i <= size; i++)
    {
        deque[end] = i; // ���� ���� ����
        index[i] = end; // �ε��� �迭�� �ε��� ����
        end++;
    }

    while (idx < num)
    {
        if (deque[start] == nums[idx]) // �� ���� ���ڰ� ������ ���ڸ� ����
        {
            index[deque[start]] = 0; // �ε��� �ʱ�ȭ
            start++;
        }
        else if ((end - start) / 2 + start >= index[nums[idx]]) // ���� �� ������ �ε����� �߰� �ε������� ���ų� ������ �������� ������
        {
            while (1)
            {
                if (deque[start] == nums[idx])
                {
                    index[deque[start]] = 0;
                    start++;
                    break;
                }
                left_rotate();
                cnt++;
            }
        }
        else if ((end - start) / 2 + start < index[nums[idx]]) // ���� �� ������ �ε����� �߰� �ε������� ũ�� ���������� ������
        {
            while (1)
            {
                if (deque[start] == nums[idx])
                {
                    index[deque[start]] = 0;
                    start++;
                    break;
                }
                right_rotate();
                cnt++;
            }
        }
        idx++; // ���� �� ���ڸ� Ȯ���Ѵ�
    }
    return cnt;
}

int main()
{
    int size, num;
    scanf("%d %d", &size, &num);

    for (int i = 0; i < num; i++)
        scanf("%d", &nums[i]);

    printf("%d", rotating(size, num, nums));

    return 0;
}