#include <stdio.h>


int main(){

    /* arithmatic operation */

    int a=10;
    int b=2;

    printf("a==b : %d\n", a==b);
    printf("a!=b : %d\n", a!=b);
    printf("a>b : %d\n", a>b);
    printf("a<b : %d\n", a<b);
    printf("a>=b : %d\n", a>=b);
    printf("a<=b : %d\n", a<=b);

    /* logical operation */

    // && - and
    // || - or
    // ! - not

    int man = 1;
    int age = 2;
    int inkorea = 1;

    printf("%d\n", man);
    printf("%d\n", !(man && age && inkorea));

    /* assignment operation */

    // =, +=, -= 등 파이썬과 동일
    man += age;
    printf("%d", man);

    return 0;
}