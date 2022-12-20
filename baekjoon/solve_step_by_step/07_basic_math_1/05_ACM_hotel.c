#include <stdio.h>

int	main(void)
{
	int	t;
	int	h, w, n;
	int	f, r;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d", &h, &w, &n);
		r = n / h + 1;
		if (n % h == 0)
			r--;
		f = (n % h) == 0 ? h : n % h;
		printf("%d%02d\n", f, r);
	}
	return (0);
}
