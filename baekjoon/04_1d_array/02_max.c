#include <stdio.h>

int	main(void)
{
	int	tmp;
	int	max = 0;
	int	idx;

	for (int i = 1; i <= 9; i++)
	{
		scanf("%d", &tmp);
		if (tmp > max)
		{
			max = tmp;
			idx = i;
		}
	}
	printf("%d\n%d\n", max, idx);
	return (0);
}
