#include <stdio.h>

int	checker(char *str)
{
	int	i = 0;
	int	alpha[26] = {0};
	char	c;

	while (str[i])
	{
		if (alpha[(int)(str[i] - 'a')])
			return (0);
		alpha[(int)(str[i] - 'a')] = 1;
		c = str[i];
		while (c == str[i])
			i++;
	}
	return (1);
}

int	main(void)
{
	int	num, cnt = 0;
	char	str[101];

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", str);
		cnt += checker(str);
	}
	printf("%d\n", cnt);
	return (0);
}
