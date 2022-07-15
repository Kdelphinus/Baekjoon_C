#include <stdio.h>

int	main(void)
{
	int	n, i = 2;

	scanf("%d", &n);
	while (n > 1)
	{
		while (n % i == 0)
		{
			printf("%d\n", i);
			n /= i;
		}
		i++;
	}
	return (0);
}
