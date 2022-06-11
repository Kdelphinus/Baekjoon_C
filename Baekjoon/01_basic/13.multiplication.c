#include <stdio.h>

int	main(void)
{
	int	a, b, tmp;

	scanf("%d\n%d", &a, &b);
	tmp = b;
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", a * (tmp % 10));
		tmp /= 10;
	}
	printf("%d\n", a * b);
	return (0);
}
