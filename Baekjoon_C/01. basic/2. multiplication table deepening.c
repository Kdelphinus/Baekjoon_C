#include <stdio.h>

int main(){

    int i, j; // ���� Ÿ�Գ��� �������
    printf("���ϴ� ���� �Է��ϼ���: ");
    scanf("%d", &i);  // &�� �� �ٿ��� ��, �� ���̸� ���� ���� �ȵ�

    for(j=1; j<10; j++){
        printf("%d x %d = %d\n", i, j, i*j);
    }

    return 0;
}