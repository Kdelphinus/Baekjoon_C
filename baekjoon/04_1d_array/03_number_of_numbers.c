#include <stdio.h>

int	main(void)
{
	int a, b, c;
	int	multiple;
	int numbers[10] = {0};

	scanf("%d\n%d\n%d", &a, &b, &c);
	multiple = a * b * c;
	while (multiple > 0)
	{
		numbers[multiple % 10]++;
		multiple /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", numbers[i]);
	return (0);
}
