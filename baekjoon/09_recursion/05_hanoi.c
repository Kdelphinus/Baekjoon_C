#include <stdio.h>

int	power(int num, int n)
{
	int	result = num;
	for (int i = 1; i < n; i++)
		result *= num;
	return (result);
}

void	hanoi(int n, int start, int end)
{
	int	other = 6 - start - end;

	if (n > 0)
	{
		hanoi(n - 1, start, other);
		printf("%d %d\n", start, end);
		hanoi(n - 1, other, end);
	}
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	printf("%d\n", power(2, n) - 1);
	hanoi(n, 1, 3);
	return (0);
}
