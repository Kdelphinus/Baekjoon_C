#include <stdio.h>

//EOF(end of file): 파일의 끝을 표현하기 위해 -1로 정의된 상수

int	main(void)
{
	int	a, b;

	while (scanf("%d %d", &a, &b) != EOF)
		printf("%d\n", a + b);
	return (0);
}
