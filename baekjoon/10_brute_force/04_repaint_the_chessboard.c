#include <stdio.h>

static int n, m;

int	repaint(char board[][m])
{
	int	w_cnt, b_cnt, flag2, min = n * m;
	char	flag;

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			w_cnt = 0;
			b_cnt = 0;
			flag = board[i][j];
			flag2 = (i + j) % 2;
			for (int y = i; y < i + 8; y++)
			{
				for (int x = j; x < j + 8; x++)
				{
					if ((x + y) % 2 == flag2 && board[y][x] != flag)
						w_cnt++;
					else if ((x + y) % 2 != flag2 && board[y][x] == flag)
						w_cnt++;
					if ((x + y) % 2 == flag2 && board[y][x] == flag)
						b_cnt++;
					else if ((x + y) % 2 != flag2 && board[y][x] != flag)
						b_cnt++;
				}
			}
			min = b_cnt < min ? b_cnt : min;
			min = w_cnt < min ? w_cnt : min;
		}
	}
	return (min);
}

int	main(void)
{
	scanf("%d %d", &n, &m);

	char	board[n][m];
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);
	printf("%d\n", repaint(board));
	return (0);
}
