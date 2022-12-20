#include <stdio.h>

int	decompose(int n)
{
	int	i;

	i = n;
	while (i > 0)
	{
		n += i % 10;
		i /= 10;
	}
	return (n);
}

int	main(void)
{
	int	n, result = 0;

	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		if (decompose(i) == n)
		{
			result = i;
			break ;
		}
	}
	printf("%d\n", result);
	return (0);
}
