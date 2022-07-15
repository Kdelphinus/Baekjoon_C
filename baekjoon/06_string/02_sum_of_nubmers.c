#include <stdio.h>

int	main(void)
{
	int		num;
	int		sum = 0;
	char	numbers[101];
	scanf("%d", &num);
	scanf("%s", numbers);
	for (int i = 0; i < num; i++)
		sum += numbers[i] - '0';
	printf("%d\n", sum);
	return (0);
}
