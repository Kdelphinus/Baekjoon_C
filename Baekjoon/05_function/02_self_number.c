#include <stdio.h>

void	self_number(int *check, int num)
{
	int	s_num;

	if (check[num] == 1)
		return ;
	while (num <= 10000)
	{
		s_num = num;
		while (num > 0)
		{
			s_num += num % 10;
			num /= 10;
		}
		num = s_num;
		if (num <= 10000)
			check[num] = 1;
	}
}

int	main(void)
{
	int	check[10001] = {0};

	for (int i = 1; i < 10001; i++)
		self_number(check, i);
	for (int i = 1; i < 10001; i++)
	{
		if (check[i] == 0)
			printf("%d\n", i);
	}
	return (0);
}
