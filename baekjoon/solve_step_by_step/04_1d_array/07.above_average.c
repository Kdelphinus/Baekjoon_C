#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		t, num;
	float	*scores;
	float	cnt, mean, total;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		cnt = 0;
		total = 0;
		scanf("%d", &num);
		scores = malloc(sizeof(float) * num);
		for (int i = 0; i < num; i++)
		{
			scanf("%f", &scores[i]);
			total += scores[i];
		}
		mean = total / num;
		for (int i = 0; i < num; i++)
			if (mean < scores[i])
				cnt++;
		// if you want %, ues %%
		printf("%.3f%%\n", cnt / num * 100);
	}
	return (0);
}
