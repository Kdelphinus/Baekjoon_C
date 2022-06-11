#include <stdio.h>

int	main(void)
{
	int	h, m;

	scanf("%d %d", &h, &m);

	if (h == 0 && m < 45)
		h = 23;
	else if (m < 45)
		h--;

	if (m >= 45)
		m -= 45;
	else
		m += 15;

	printf("%d %d\n", h, m);
	return (0);
}
