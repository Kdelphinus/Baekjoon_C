#include <stdio.h>

int	main(void)
{
	int	n = 0, cnt = 0;
	char	str[1000000];
	
	scanf("%[^\n]s", str);
	while (str[n] == 32)
		n++;
	while (str[n])
	{
		if (str[n] == 32)
			cnt++;
		n++;
	}
	if (str[n - 1] != 32)
		cnt++;
	printf("%d\n", cnt);
	return (0);
}
