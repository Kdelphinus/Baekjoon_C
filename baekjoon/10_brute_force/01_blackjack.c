#include <stdio.h>

int	main(void)
{
	int	n, m, tmp, max = 0;

	scanf("%d %d", &n, &m);
	int	cards[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &cards[i]);

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				tmp = cards[i] + cards[j] + cards[k];
				if (max < tmp && tmp <= m)
					max = tmp;
			} 
		}
	}
	printf("%d\n", max);
	return (0);
}
