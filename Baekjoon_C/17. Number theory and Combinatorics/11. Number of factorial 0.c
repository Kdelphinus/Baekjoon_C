/**
 * @file 11. Number of factorial 0.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief ���μ����� Ȱ��
 * @date 2021-06-23 19:11:38
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    printf("%d", num / 5 + num / 25 + num / 125); // 2�� ����� ���⿡ 5�� ����� ������ �κи� ���ɴ�

    return 0;
}