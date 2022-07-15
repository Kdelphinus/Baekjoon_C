#include <stdio.h>

int	main(void)
{
	int	cnt = 0;
	int	tmp;
	int	numbers[42] = {0};

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &tmp);
		if (numbers[tmp % 42] == 0)
		{
			cnt++;
			numbers[tmp % 42]++;
		}
	}
	printf("%d\n", cnt);
	return (0);
}
