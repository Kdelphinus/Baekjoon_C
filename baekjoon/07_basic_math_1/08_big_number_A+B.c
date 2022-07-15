#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	idx = 0;
	int	len_n1, len_n2, tmp, up = 0;
	char	n1[10001], n2[10001];
	char	sum[10002];

	scanf("%s %s", n1, n2);
	len_n1 = strlen(n1) - 1;
	len_n2 = strlen(n2) - 1;
	while (len_n1 >= 0 && len_n2 >= 0)
	{
		tmp = (n1[len_n1] - '0') + (n2[len_n2] - '0') + up;
		up = tmp > 9 ? 1 : 0;
		tmp = tmp > 9 ? tmp % 10 : tmp;
		sum[idx++] = tmp + '0';
		len_n1--;
		len_n2--;
	}
	while (len_n1 >= 0)
	{
		tmp = (n1[len_n1] - '0') + up;
		up = tmp > 9 ? 1 : 0;
		tmp = tmp > 9 ? tmp % 10 : tmp;
		sum[idx++] = tmp + '0';
		len_n1--;
	}
	while (len_n2 >= 0)
	{
		tmp = (n2[len_n2] - '0') + up;
		up = tmp > 9 ? 1 : 0;
		tmp = tmp > 9 ? tmp % 10 : tmp;
		sum[idx++] = tmp + '0';
		len_n2--;
	}
	if (up == 1)
		sum[idx++] = '1';
	for (int i = idx - 1; i >= 0; i--)
		printf("%c", sum[i]);
	printf("\n");
	return (0);
}
