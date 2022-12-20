#include <stdio.h>

int	main(void)
{
	int	num;
	int	fix, cost, price;

	scanf("%d %d %d", &fix, &cost, &price);
	if (price <= cost)
		printf("-1\n");
	else
	{
		num = fix / (price - cost);
		printf("%d\n", num + 1);
	}
	return (0);
}
