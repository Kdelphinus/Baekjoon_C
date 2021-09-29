#include <stdio.h>
#define pi 3.1415 // 상수 정의

int main(){
    
    int age = 27;
    float weight;
    char letter_grade = 'A';
    // double: 긴 소수

    weight = 65.5;

    printf("I'm %d years old \n", age);
    printf("I'm %.1fkg \n", weight);
    printf("I got %c \n", letter_grade);

    return 0;
}