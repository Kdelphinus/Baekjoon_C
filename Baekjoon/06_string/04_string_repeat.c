#include <stdio.h>

int	main(void)
{
	int	num, repeat;
	char	str[21];

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %s", &repeat, str);
		for (int j = 0; str[j]; j++)
		{
			for (int k = 0; k < repeat; k++)
				printf("%c", str[j]);
		}
		printf("\n");
	}
	return (0);
}
