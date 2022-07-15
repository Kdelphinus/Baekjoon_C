#include <stdio.h>

int	main(void)
{
	int		t;
	int		score;
	int		total;
	char	result[81];

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%s", result);
		score = 0;
		total = 0;
		for (int j = 0; result[j]; j++)
		{
			if (result[j] == 'O')
				score++;
			else
				score = 0;
			total += score;
		}
		printf("%d\n", total);
	}
	return (0);
}
