#include <stdio.h>

int	is_prime(int n)
{
	int	i = 2;
	
	if (n == 1)
		return (0);
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
	int	t;
	int	n;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (int j = n / 2; j >= 2; j--)
		{
			if (is_prime(j) && is_prime(n - j))
			{
				printf("%d %d\n", j, n - j);
				break ;
			}
		}
	}
	return (0);
}
