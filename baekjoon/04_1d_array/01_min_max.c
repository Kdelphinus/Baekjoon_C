#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	num, tmp;
	int min = 1000000;
	int	max = -1000000;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &tmp);
		min = min > tmp ? tmp : min;
		max = max < tmp ? tmp : max;
	}

	printf("%d %d\n", min, max);
	return (0);
}
