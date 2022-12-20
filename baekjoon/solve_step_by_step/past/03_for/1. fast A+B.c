#include <stdio.h>

void main() {

    int test, a, b, i;

    scanf("%d", &test);

    for(i = 0; i < test; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }

}