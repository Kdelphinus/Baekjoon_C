#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[] = "283";
    char s2[] = "253asdf698";
    int num1, num2;

    num1 = atoi(s1);      // ���ڿ��� ���������� ����
    printf("%d\n", num1); // 283

    num2 = atoi(s2);    // ���ڰ� ���� ���ڿ��� ��ȯ�ϸ�
    printf("%d", num2); //253, ���ڰ� ������ ������ ���ڸ� ��ȯ

    return 0;
}