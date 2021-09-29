#include <stdio.h>

int main(){

    char a = 'a';  // 변수는 ''로 지정

    if(a == 'a' || a == 'b'){
        if(a == 'a'){
            printf("a is A");
        }
        else{
            printf("a is B");
        }
    }
    else{
        printf("a is not A, B");
    }

    int b = 4;
    
    switch(a){

        case 1:
            printf("1");
            break;
        case 2:
            printf("2");  // break를 안 걸면 case 순서대로 쭉 내려감, 이를 통해 5 이하 숫자를 모으거나 할 수 있음
            break;
        case 3:
            printf("3");
            break;
        default:
            prinf("default")
            break;
    }

    return 0;
}