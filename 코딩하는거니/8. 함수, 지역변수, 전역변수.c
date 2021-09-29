#include <stdio.h>

// 함수의 지정: (리턴타입) (함수의 이름) (인자)
// 리턴타입: int, char 등 / void는 리턴값 없음 
// 함수의 이름: 이름 
// 인자: 어떤 값을 받고 함수를 실행할 것인가, 받는 값이 없으면 비워두기

// 이곳에다 변수를 지정하면 전역변수로 지정됨

int star(int i){
    if(i == 1){
        printf("****************\n");
        return 11;
    }
    else if(i == 2){
        printf("@@@@@@@@@@@@@@@@@\n");
        return 22;
    }
    else{
        printf("error\n");
    }
    return 33;
}

int add(int a, int b){
    return a + b;
}

int main(){

    int a = 5;
    int b = 8;

    printf("%d + %d = %d\n", a, b, add(a, b));

    int msg;
    int i;

    for(i=1; i<=3; i++){
        printf("\n안녕%d\n", i);
        msg = star(i);
        if(msg == 33){
            printf("\n**에러 발생!**\n");
        }

    // printf도 총 입력된 값의 개수를 리턴
    // \n도 하나로 쳐서 합쳐서 리턴됨
    msg = printf("\nabcde\n");
    printf("%d\n", msg);
    }

    return 0;
}