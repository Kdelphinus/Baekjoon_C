#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
	int	num1 = *(int *)a;
	int	num2 = *(int *)b;

	if (num1 < num2)
		return (-1);
	if (num1 > num2)
		return (1);
	return (0);
}

int	min(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}

int	max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

int	mode(int check[])
{
	int	r, min_n = 0;
	int	flag = 0;

	for (int i = -4000; i < 4001; i++)
	{
		if (min_n < check[i + 4000])
		{
			min_n = check[i + 4000];
			flag = 1;
			r = i;
		}
		else if (min_n == check[i + 4000] && flag < 2)
		{
			flag++;
			r = i;
		}
	}
	return (r);
}

int	main(void)
{
	int	n, sum = 0;
	int	min_n = 4000, max_n = -4000;
	scanf("%d", &n);

	int	num[n], check[8001] = {0};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
		check[num[i] + 4000]++;
		max_n = max(max_n, num[i]);
		min_n = min(min_n, num[i]);
	}
	qsort(num, sizeof(num) / sizeof(int), sizeof(int), compare);

	float	mean = (float)sum / n;
	printf("%d\n", (int)(mean >= 0 ? mean + 0.5 : mean - 0.5));
	printf("%d\n", num[n / 2]);
	printf("%d\n", mode(check));
	printf("%d\n", max_n - min_n);
	return (0);
}
