#include <stdio.h>

// � ���� ����Ű�� ���� ���� ���� ������
// Ÿ�Ժ��� �ٸ� �����͸� ����

int swap (int num1, int num2){

    int temp;

    temp = num1;
    num1 = num2;
    num2 = temp;

    return 0;
}

int swap2 (int* num1, int* num2){

    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;

    return 0;
}

int main(){

    int a = 9;
    int b = 10;

    // *(asterisk): �����͸� ������ ��, �Ǵ� �ش� �ּ� ���� ������ �� ���
    // �����ʹ� ���۷���, �� ���� �ּҸ� ����Ų��
    int * ptr;
    int * ptr2;

    // &(ampersand): �ּҸ� ����ų ��, ���
    ptr = &a;
    ptr2 = &b;

    // %p: printf �Լ��� ���� ����
    // %x: 16������ ����
    printf("address of a is %p", &a);
    printf("\npointing of ptr is %p", ptr);
    printf("\nvalue of ptr is %d", *ptr);

    // �����ͳ��� ���� ����
    printf("\n\nb - a = %d", *ptr2 - *ptr);

    // ���� ���� �ٲٱ�
    printf("\n\na: %d, b: %d\n", a, b);

    swap(a, b);
    printf("\na�� b�� ���� swap �Լ��� �־��� ��\n");
    printf("a: %d, b: %d\n", a, b); 

    swap2(ptr, ptr2);
    printf("\nptr�� ptr2�� ���� swap2 �Լ��� �־��� ��\n");
    printf("a: %d, b: %d\n", a, b); 

    // �迭���� ������
    char arr[6] = "Hello";

    char* arr_ptr;
    arr_ptr = &arr[0]; // �迭�� �������� ����

    printf("\n*arr_ptr: %c\n", *arr_ptr);
    printf("arr_ptr[2]: %c\n", arr_ptr[2]);

    // �����ڵ� �켱������ ����
    // *�� +���� �켱����, �׷��⿡ ��ȣ�� ���ϸ� ���� �ҷ����� �� ���� 1�� ���� ���� ����
    printf("\n*arr_ptr + 1: %c\n", *arr_ptr + 1);
    printf("*(arr_ptr + 1): %c\n", *(arr_ptr + 1));

    // char�� 1byte���� 1�� ���ϸ� �������� �̵�
    // int, float�� ������ ũ�Ⱑ 4byte�̱⿡ 4�� ���ؾ� ���� ������ �Ѿ

    // �����ʹ� �����͸� ����Ű�� ���� ������, ���� �����͸� ����Ű�� Ʈ���� ������ �� �����͸� ����Ű�� �����͵� ���
    

    return 0;
}