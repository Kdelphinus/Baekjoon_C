#include <stdio.h>

int	main(void)
{
	int	num, limit = 1; 
	int	cnt = 1;

	scanf("%d", &num);
	while (num > limit)
	{
		limit += 6 * cnt;
		cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}
