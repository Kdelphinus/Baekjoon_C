#include <stdio.h>

int	main(void)
{
	int	sum = 0;
	int	num, i;
	int	up, down;

	scanf("%d", &num);
	for (i = 1; ; i++)
	{
		sum += i;
		if (sum >= num)
			break ;
	}
	if (i % 2)
	{
		up = 1;
		down = i;
	}
	else
	{
		up = i;
		down = 1;
	}
	for (int j = 0; j < sum - num; j++)
	{
		if (i % 2)
		{
			up++;
			down--;
		}
		else
		{
			up--;
			down++;
		}
	}
	printf("%d/%d\n", up, down);
	return (0);
}
