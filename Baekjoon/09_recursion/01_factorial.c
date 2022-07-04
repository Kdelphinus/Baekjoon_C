#include <stdio.h>

void	factorial(int n)
{
	int	result = 1;

	for (int i = 2; i <= n; i++)
		result *= i;
	printf("%d\n", result);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	factorial(n);
	return (0);
}
