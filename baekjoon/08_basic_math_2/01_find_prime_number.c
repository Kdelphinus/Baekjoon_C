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
	int	n, tmp, cnt = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (is_prime(tmp))
			cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}
