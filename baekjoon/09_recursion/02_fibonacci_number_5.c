#include <stdio.h>

void	fibonacci(int n)
{
	int	tmp, prev = 0, curr = 1;

	for (int i = 1; i < n; i++)
	{
		tmp = curr;
		curr += prev;
		prev = tmp;
	}
	printf("%d\n", n == 0 ? prev : curr);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	fibonacci(n);
	return (0);
}
