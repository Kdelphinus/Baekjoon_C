/**
 * @file 06. rotating queue.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 배열 크기가 왜 틀리는지 찾지 못함
 * @date 2021-07-03 20:12:29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int deque[400]; // 덱 구성, 왜 400정도의 크기가 필요한가?(102정도면 충분하지 않는가?)
int nums[90];   // 뽑아야 할 숫자를 담을 배열, 왜 90정도의 크기가 필요한가?(51정도면 충분하지 않는가?)
int index[51];  // 숫자들이 들어있는 덱의 인덱스(index[1]: 덱에 1이 들어간 인덱스가 저장되어 있음)
int start = 51, end = 51;

void left_rotate() // 왼쪽으로 돌림(맨 앞의 숫자가 맨 뒤로 간다)
{
    deque[end++] = deque[start++];
    index[deque[end - 1]] = end - 1;
}

void right_rotate() // 오른쪽으로 돌림(맨 뒤의 숫자가 맨 앞으로 온다)
{
    deque[--start] = deque[--end];
    index[deque[start]] = start;
}

int rotating(int size, int num, int nums[])
{
    int idx = 0, cnt = 0; // 빼야할 숫자를 가리키는 인덱스, 회전 횟수

    for (int i = 1; i <= size; i++)
    {
        deque[end] = i; // 덱에 숫자 저장
        index[i] = end; // 인덱스 배열에 인덱스 저장
        end++;
    }

    while (idx < num)
    {
        if (deque[start] == nums[idx]) // 맨 앞의 숫자가 빼야할 숫자면 뺀다
        {
            index[deque[start]] = 0; // 인덱스 초기화
            start++;
        }
        else if ((end - start) / 2 + start >= index[nums[idx]]) // 현재 뺄 숫자의 인덱스가 중간 인덱스보다 같거나 작으면 왼쪽으로 돌린다
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
        else if ((end - start) / 2 + start < index[nums[idx]]) // 현재 뺄 숫자의 인덱스가 중간 인덱스보다 크면 오른쪽으로 돌린다
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
        idx++; // 다음 뺄 숫자를 확인한다
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