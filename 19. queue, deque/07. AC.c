/**
 * @file 07. AC.c
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 백준 해답 중 하나, 풀이 방식은 동일하나 구현 방식이 간단
 * @date 2021-07-08 21:44:20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char p[100001], x[1000001]; // p: 명령들, x: 배열

int main()
{
    /** 
    T: 테스트 횟수
    t: 배열이 뒤집혔는지 확인하는 변수
    n: 배열에 들어있는 수의 개수
    i: 배열의 시작 인덱스
    j: 배열의 끝 인덱스
    error: error가 뜨는지 판별할 변수
    **/
    int T, t, n, i, j, error;

    scanf("%d", &T);

    while (T--)
    {
        error = 0; // 현재는 error이 아니다

        scanf("%s %d %s", p, &n, x);

        i = 1;             // 배열의 시작 인덱스(괄호를 제외하고)
        j = strlen(x) - 2; // 배열의 끝 인덱스(괄호를 제외하고)
        t = 0;             // R명령이 짝수번 있음

        for (int k = 0; p[k]; k++)
        {
            if (p[k] == 'R')     // R명령이면
                t = (t + 1) % 2; // 배열이 뒤집혔는지 최신화
            else                 // D명령이면
            {
                if (n == 0) // 배열 안에 숫자가 없다면
                {
                    error = 1; // error
                    break;     // 명령 종료
                }

                if (t) // 배열이 뒤집힌 상태면
                {
                    while (x[j] != ',' && x[j] != '[') // ','나 '['이 나오기 전까지 끝 인덱스를 앞으로 당긴다
                        j--;

                    j--; // 숫자가 마지막이 되도록 한 번 더 뺸다
                }
                else // 배열이 뒤집히지 않은 상태면
                {
                    while (x[i] != ',' && x[i] != ']') // ','나 ']'이 나오기 전까지 시작 인덱스를 뒤로 민다
                        i++;

                    i++; // 숫자가 처음이 되도록 한 번 더 민다
                }
                n--; // 숫자를 하나 빼준다
            }
        }

        if (error) // error가 발생했을 때
            printf("error\n");
        else // error가 발생하지 않았을 때
        {
            printf("["); // 여는 괄호

            if (t) // 배열이 뒤집힌 상태면
            {
                for (int k = j; k >= i; k--) // 뒤에서부터 출력한다
                {
                    if (x[k - 1] == '[' || x[k - 1] == ',') // '['나 ',' 전에
                    {
                        printf("%d", atoi(&x[k])); // 문자열을 정수형으로 변환

                        if (k > i) // 뒤에 숫자가 더 있다면
                            printf(",");
                    }
                }
            }
            else // 배열이 원 상태이면
            {
                for (int k = i; k <= j; k++) // 차례대로 출력
                    printf("%c", x[k]);
            }

            printf("]\n"); // 닫는 괄호
        }
    }

    return 0;
}