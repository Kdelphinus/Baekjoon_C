#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		num;
	int		max = 0;
	float	*scores;
	float	total = 0;

	scanf("%d", &num);
	scores = malloc(sizeof(float) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%f", &scores[i]);
		if (scores[i] > max)
			max = scores[i];
	}
	for (int i = 0; i < num; i++)
		total += (scores[i] / max) * 100;
	printf("%.2f\n", total / num);
	return (0);
}
