#include <stdio.h>

int	main(void)
{
	int		idx, max = 0;
	int		check[26] = {0};
	char	result = '?';
	char	str[1000000];

	scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		idx = str[i] - 'A';
		if (idx > 25)
			idx -= 32;
		check[idx]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (max < check[i])
		{
			max = check[i];
			result = i + 'A';
		}
		else if (max > 0 && max == check[i])
			result = '?';
	}
	printf("%c\n", result);
	return (0);
}
