#include <stdio.h>

char	*max(char *n1, char *n2)
{
	for (int i = 2; i >= 0; i--)
	{
		if (n1[i] > n2[i])
			return (n1);
		else if (n1[i] < n2[i])
			return (n2);
	}
	return (n1);
}

int	main(void)
{
	char *max_n;
	char n1[3], n2[3];
	
	scanf("%s %s", n1, n2);
	max_n = max(n1, n2);
	for (int i = 2; i >= 0; i--)
		printf("%c", max_n[i]);
	printf("\n");
	return (0);
}
