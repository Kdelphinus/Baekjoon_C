#include <stdio.h>

int	main(void)
{
	int	day;
	int	a, b, v;

	scanf("%d %d %d", &a, &b, &v);

	if (a >= v)
		day = 1;
	else
	{
		day = (v - a) / (a - b) + 1;
		if ((v - a) % (a - b))
			day++;
	}
	printf("%d\n", day);
	return (0);
}
