#include <stdio.h>

int	film_name(int name)
{
	int	flag = 0;

	while (name > 0 && flag < 3)
	{
		if (name % 10 == 6)
			flag++;
		else
			flag = 0;
		name /= 10;
	}
	return (flag == 3 ? 1 : 0);
}

int	main(void)
{
	int	n, name = 665;

	scanf("%d", &n);
	while (n > 0)
	{
		name++;
		if (film_name(name))
			n--;
	}
	printf("%d\n", name);
	return (0);
}
