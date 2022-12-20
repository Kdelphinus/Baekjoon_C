#include <stdio.h>

int	check_han(int num)
{
	int	prev;
	int	curr;
	int	diff;

	prev = num % 10;
	num /= 10;
	curr = num % 10;
	num /= 10;
	diff = curr - prev;
	while (num > 0)
	{
		prev = curr;
		curr = num % 10;
		if (diff != curr - prev)
			return (0);
		num /= 10;
	}
	return (1);
}

void	han_number(int num)
{
	int	i = 100;
	int	cnt = 99;

	if (num < 100)
	{
		printf("%d\n", num);
		return ;
	}
	
	while (i <= num)
	{
		if (check_han(i))
			cnt++;
		i++;
	}
	printf("%d\n", cnt);
}

int	main(void)
{
	int	num;

	scanf("%d", &num);
	han_number(num);
	return (0);
}
