#include <stdio.h>

int	main(void)
{
	int cnt = 1;
	int	n, tmp;
	int	result;

	scanf("%d", &n);
	result = (n % 10) * 10 + (n / 10 + n % 10) % 10;
	while (result != n)
	{
		tmp = result;
		result = (tmp % 10) * 10 + (tmp / 10 + tmp % 10) % 10;
		cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}
