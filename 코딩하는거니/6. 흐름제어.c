#include <stdio.h>
#include <stdlib.h> // rand �Լ�
#include <time.h>  // time �Լ�

int main(){

    """break""";
    // c�� �������� �ð��� �����Ͽ� �̱⿡ �ð��� �ʱ�ȭ���� ������ ������ �������� ����
    srand(time(NULL)); // �׷��⿡ �ð� �ʱ�ȭ

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
    """�ڵ��� �帧�� �� ���� ���ϱ� ������ ������� ����""";

    printf("hi \n");

    goto end; // end�� �ٷ� �̵�

    printf("bye \n");
    printf("hello \n");

end:
    printf("!!end!! \n");

    return 0;
}