/**
 * @file 04. Missing parentheses.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-06-17 22:48:06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min_value(char str[])
{
    int result = 0, size, i = 0, j = 0, flag = 0; // 계산 값, 문자열 길이, 문자열 탐색 인덱스, 임시 저장 인덱스, -부호가 나왔는가
    char tmp[6];                                  // 임시 저장 배열

    size = strlen(str); // 문자열의 길이

    while (i < size)
    {
        if (flag) // -가 나온 뒤론 계속 빼준다
        {
            if (str[i] == '+' || str[i] == '-')
            {
                result -= atoi(tmp); // 문자열을 정수형으로 변환하여 빼줌
                j = 0;
                for (int k = 0; k < 6; k++) // 임시 저장 배열 초기화
                    tmp[k] = '\0';
            }
            else
            {
                tmp[j] = str[i]; // 임시 저장 배열에 문자열 저장
                j++;
            }
            i++;
        }
        else // -가 나오지 않았다면
        {
            if (str[i] == '+') // 더해주거나
            {
                result += atoi(tmp);
                j = 0;
                for (int k = 0; k < 6; k++)
                    tmp[k] = '\0';
            }
            else if (str[i] == '-') // 빼주고 -가 나왔다고 설정
            {
                result += atoi(tmp);
                flag = 1;
                j = 0;
                for (int k = 0; k < 6; k++)
                    tmp[k] = '\0';
            }
            else
            {
                tmp[j] = str[i];
                j++;
            }
            i++;
        }
    }

    // 마지막 숫자 계산
    if (flag)
        result -= atoi(tmp);
    else
        result += atoi(tmp);

    return result;
}

int main()
{
    char str[51];
    scanf("%s", str);

    printf("%d", min_value(str));

    return 0;
}