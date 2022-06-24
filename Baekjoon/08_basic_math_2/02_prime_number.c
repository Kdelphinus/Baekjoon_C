#include <stdio.h>

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	is_prime(int n)
{
	int	i = 2;

	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	n, m;
	int	min_n = 10000, sum = 0;

	scanf("%d\n%d", &n, &m);
	for (int i = n; i <= m; i++)
	{
		if (is_prime(i))
		{
			min_n = min(min_n, i);
			sum += i;
		}
	}
	if (sum)
		printf("%d\n%d\n", sum, min_n);
	else
		printf("-1\n");
	return (0);
}
