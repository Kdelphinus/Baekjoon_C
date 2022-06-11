#include <stdio.h>

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	main(void)
{
	int	first, second, third;

	scanf("%d %d %d", &first, &second, &third);
	if (first == second && second == third)
		printf("%d", 10000 + first * 1000);
	else if (first == second)
		printf("%d", 1000 + first * 100);
	else if (first == third)
		printf("%d", 1000 + first * 100);
	else if (second == third)
		printf("%d", 1000 + second * 100);
	else
		printf("%d", max(max(first, second), third) * 100);
	printf("\n");
	return (0);
}
