#include <stdio.h>

int main(){

    int i, j; // 같은 타입끼리 묶어놓기
    printf("원하는 단을 입력하세요: ");
    scanf("%d", &i);  // &를 꼭 붙여야 함, 안 붙이면 변수 지정 안됨

    for(j=1; j<10; j++){
        printf("%d x %d = %d\n", i, j, i*j);
    }

    return 0;
}