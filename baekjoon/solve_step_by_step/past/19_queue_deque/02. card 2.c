/**
 * @file 02. card 2.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-01 23:44:07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int queue[1000001]; // 큐, 시작위치를 옮기는 방식이기에 최대 크기의 두배가 필요함
int tmp_index;      // 시작 위치

void pop()
{
    tmp_index++; // 시작 위치를 옮겨 맨 앞의 값을 제거
}

void back(int index)
{
    queue[index] = queue[tmp_index]; // 맨 앞의 값을 맨 뒤로 옮기고
    tmp_index++;                     // 시작 위치를 옮겨 맨 앞의 값을 제거
}

int card(int num)
{
    int flag = 0, index;
    index = num;                  // 배열 끝
    for (int i = 0; i < num; i++) // 숫자 넣기
        queue[i] = i + 1;

    while (index - tmp_index > 1) // 배열에 하나만 남을 때까지 반복
    {
        if (flag) // flag가 1이면 맨 앞의 카드를 맨 뒤로 옮기고
        {
            back(index);
            flag = 0; // 다음에 카드를 뺴라고 지시
            index++;  // 맨 뒤에 카드 한 장 추가
        }
        else // flag가 0이면 맨 앞의 카드를 뺀다
        {
            pop();
            flag = 1; // 다음에 카드를 뒤로 옮기라고 지시
        }
    }

    return queue[tmp_index]; // 시작 위치의 카드가 남은 카드
}

int main()
{
    int num;
    scanf("%d", &num);

    printf("%d", card(num));

    return 0;
}