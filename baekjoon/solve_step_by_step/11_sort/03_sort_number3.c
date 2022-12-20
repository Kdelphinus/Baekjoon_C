#include <stdio.h>

int	main(void)
{
	int	n, tmp;
	int	numbers[10001] = {0};

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		numbers[tmp]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < numbers[i]; j++)
			printf("%d\n", i);
	}
	return (0);
}
