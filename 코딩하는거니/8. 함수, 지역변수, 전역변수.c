#include <stdio.h>

// �Լ��� ����: (����Ÿ��) (�Լ��� �̸�) (����)
// ����Ÿ��: int, char �� / void�� ���ϰ� ���� 
// �Լ��� �̸�: �̸� 
// ����: � ���� �ް� �Լ��� ������ ���ΰ�, �޴� ���� ������ ����α�

// �̰����� ������ �����ϸ� ���������� ������

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
        printf("\n�ȳ�%d\n", i);
        msg = star(i);
        if(msg == 33){
            printf("\n**���� �߻�!**\n");
        }

    // printf�� �� �Էµ� ���� ������ ����
    // \n�� �ϳ��� �ļ� ���ļ� ���ϵ�
    msg = printf("\nabcde\n");
    printf("%d\n", msg);
    }

    return 0;
}