#include <stdio.h>
#include <string.h>

int main()
{
    // 알파벳 시작 위치를 저장할 리스트
    int alphabet[26];

    // 배열 안 요소를 모두 -1로 만들기
    for (int i = 0; i < 26; i++){
        alphabet[i] = -1;
    }

    // 입력 받을 문자열
    char str[100];
    scanf("%s", str);

    // 문자열 길이를 받을 변수
    int size, index = 0;
    size = strlen(str);

    for (int i = 0; i < size; i++){
        index = str[i] - 97;
        
        if (alphabet[index] == -1){
            alphabet[index] = i;
        }
    }

    for (int i = 0; i< 26; i++){
        printf("%d ", alphabet[i]);
    }

    return 0;
}