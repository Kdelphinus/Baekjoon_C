#include <stdio.h>

int main(){

    int i;

    // for, ���� �������� ��Ȯ�� �� �� 
    // (���۰�; ��������; �ݺ��� ������ �� Ȱ��)
    // �ʱⰪ, ������ ����, ���� ����, �ʱⰪ�� � ������ �� ���ΰ�
    for (i=0; i<100; i++){
        printf("Hello World %d\n", i);
    }

    // while(��������){����}, Ư�� ����Ǵ� ��Ȳ�� ���� ��
    // while(1): ���� ����, 0�� false, ������ ���ڴ� ��� true
    i = 0;

    while(i<10){
        printf("Hello World %d\n", i);
        i++; // �ʱⰪ�� � ������ �� ���ΰ�
    }

    // while�� ���� ���� do�� ���� ����
    // �� ��, while�� ����
    i = 0;
    do{
        printf("Hello World %d\n", i);
        i++;
    }while(i<15);    

    return 0;
}