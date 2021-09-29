#include <stdio.h>

int main(){

    int i;

    // for, 언제 끝나는지 명확히 알 때 
    // (시작값; 언제까지; 반복할 때마다 할 활동)
    // 초기값, 끝나는 조건, 내용 실행, 초기값에 어떤 연산을 할 것인가
    for (i=0; i<100; i++){
        printf("Hello World %d\n", i);
    }

    // while(종결조건){내용}, 특정 종결되는 상황이 있을 때
    // while(1): 무한 루프, 0은 false, 나머지 숫자는 모두 true
    i = 0;

    while(i<10){
        printf("Hello World %d\n", i);
        i++; // 초기값에 어떤 연산을 할 것인가
    }

    // while을 들어가기 전에 do를 먼저 실행
    // 그 후, while을 실행
    i = 0;
    do{
        printf("Hello World %d\n", i);
        i++;
    }while(i<15);    

    return 0;
}