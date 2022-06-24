#include <stdio.h>

void	initial(int	building[][15])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			if (i == 0)
				building[i][j] = j;
			else if (j == 1)
				building[i][j] = 1;
			else
				building[i][j] = building[i - 1][j] + building[i][j - 1];
		}
	}
}

int	main(void)
{
	int	t;
	int	k, n;
	int	building[15][15];

	scanf("%d", &t);
	initial(building);
	for (int i = 0; i < t; i++)
	{
		scanf("%d\n%d", &k, &n);
		printf("%d\n", building[k][n]);
	}
	return (0);
}
