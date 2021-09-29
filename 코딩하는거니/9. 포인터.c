#include <stdio.h>

// 어떤 값을 가리키기 위해 쓰는 것이 포인터
// 타입별로 다른 포인터를 가짐

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

    // *(asterisk): 포인터를 선언할 때, 또는 해당 주소 값에 접근할 때 사용
    // 포인터는 레퍼런스, 즉 값의 주소를 가리킨다
    int * ptr;
    int * ptr2;

    // &(ampersand): 주소를 가리킬 때, 사용
    ptr = &a;
    ptr2 = &b;

    // %p: printf 함수의 지정 서식
    // %x: 16진수로 리턴
    printf("address of a is %p", &a);
    printf("\npointing of ptr is %p", ptr);
    printf("\nvalue of ptr is %d", *ptr);

    // 포인터끼리 연산 가능
    printf("\n\nb - a = %d", *ptr2 - *ptr);

    // 값을 서로 바꾸기
    printf("\n\na: %d, b: %d\n", a, b);

    swap(a, b);
    printf("\na와 b를 직접 swap 함수에 넣었을 때\n");
    printf("a: %d, b: %d\n", a, b); 

    swap2(ptr, ptr2);
    printf("\nptr과 ptr2를 직접 swap2 함수에 넣었을 때\n");
    printf("a: %d, b: %d\n", a, b); 

    // 배열에서 포인터
    char arr[6] = "Hello";

    char* arr_ptr;
    arr_ptr = &arr[0]; // 배열의 시작점을 복사

    printf("\n*arr_ptr: %c\n", *arr_ptr);
    printf("arr_ptr[2]: %c\n", arr_ptr[2]);

    // 연산자도 우선순위가 있음
    // *은 +보다 우선순위, 그렇기에 괄호를 안하면 값을 불러오고 그 값에 1을 더한 값이 나옴
    printf("\n*arr_ptr + 1: %c\n", *arr_ptr + 1);
    printf("*(arr_ptr + 1): %c\n", *(arr_ptr + 1));

    // char는 1byte여서 1을 더하면 다음으로 이동
    // int, float을 쓰려면 크기가 4byte이기에 4를 더해야 다음 값으로 넘어감

    // 포인터는 포인터를 가리키는 더블 포인터, 더블 포인터를 가리키는 트리플 포인터 등 포인터를 가리키는 포인터도 사용
    

    return 0;
}