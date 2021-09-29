#include <stdio.h>
#include <string.h>

int main()
{
    char arr[100] = "gunny";
    char copy[100] = "asdfwerjiogsas";
    char ch = 'u';
    char *pos;
    int box, same;

    // 문자열 크기를 구해주는 함수
    box = strlen(arr);
    printf("%d\n", box);

    // 문자열 복사
    strcpy(copy, arr);    // (붙여넣기 할 리스트, 복사할 리스트)
    printf("%s\n", copy); // gunny가 나옴

    // 문자열이 같은지 비교, 같으면 0, 다르면 0외의 숫자를 리턴
    same = strcmp(arr, copy);

    if (same == 0) //if (!same)도 같은 의미, 0이 False를 의미하기 때문
    {
        printf("Same String\n");
    }
    else
    {
        printf("Different String\n");
    }

    // 스트링 추가, 합치기
    strcat(arr, copy); //(합쳐지는 리스트, 합칠 내용이 있는 리스트)
    printf("%s\n", arr);

    // 스트링 안에 문자 찾기
    pos = strchr(arr, ch);     // 처음 발견한 위치의 포인터를 리턴
    printf("%s\n", pos);       // 주소를 찾아주기에 발견한 문자부터 뒤의 문자들을 전부 리턴
    printf("%d\n", pos - arr); // 이를 활용하여 인덱스를 받을 수 있다

    // 변형
    // 두 개의 배열 외에 숫자 또는 문자를 하나 입력 받는다
    // 그 숫자만큼만 비교하거나 카피한다
    // strncat
    // strncmp
    // strncpy

    // 뒤에서부터 문자를 찾아준다
    // strrchr

    return 0;
}