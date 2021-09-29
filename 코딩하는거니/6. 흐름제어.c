#include <stdio.h>
#include <stdlib.h> // rand 함수
#include <time.h>  // time 함수

int main(){

    """break""";
    // c는 랜덤수를 시간과 관련하여 뽑기에 시간을 초기화하지 않으면 동일한 패턴으로 나옴
    srand(time(NULL)); // 그렇기에 시간 초기화

    while(1){

        int rnd = rand()%1000 + 1;
        printf("%d\n", rnd);

        if(rnd==555){
            break;
        }
    }

    """continue""";

    int i;

    for(i=0; i<=9; i++){

        if(i%2 == 0){
            continue;
        }

        printf("Hello World %d \n", i);

    }

    """goto""";
    """코드의 흐름을 잘 알지 못하기 때문에 권장되지 않음""";

    printf("hi \n");

    goto end; // end로 바로 이동

    printf("bye \n");
    printf("hello \n");

end:
    printf("!!end!! \n");

    return 0;
}