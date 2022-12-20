#include <stdio.h>

int	main(void)
{
	int	n, result;
	int	five, three = 0;

	scanf("%d", &n);
	five = n / 5;
	while (five >= 0)
	{
		three = n - (five * 5);
		if (three % 3 == 0)
			break;
		five--;
	}
	result = five >=0 ? five + three / 3 : -1;
	printf("%d\n", result);
	return (0);
}
