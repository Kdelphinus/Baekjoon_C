#include <stdio.h>

int main(){

    char a = 'a';  // ������ ''�� ����

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
            printf("2");  // break�� �� �ɸ� case ������� �� ������, �̸� ���� 5 ���� ���ڸ� �����ų� �� �� ����
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