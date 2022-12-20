#include <stdio.h>

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
	int	m, n;

	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; i++)
	{
		if (is_prime(i))
			printf("%d\n", i);
	}
	return (0);
}
