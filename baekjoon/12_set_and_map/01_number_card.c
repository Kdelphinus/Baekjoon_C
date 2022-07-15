#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
	int n1 = *(int *)a;
	int n2 = *(int *)b;

	if (n1 < n2)
		return (-1);
	if (n1 > n2)
		return (1);
	return (0);
}

int	binary_search(int card[], int num, int n)
{
	int start = 0, end = n - 1;
	int	mid = (end - start) / 2;

	while (start <= end)
	{
		if (card[mid] == num)
			return (1);
		else if (card[mid] > num)
			end = mid  - 1;
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	return (0);
}

int	main(void)
{
	int	n, m, num;
	scanf("%d", &n);

	int	card[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);

	qsort(card, n, sizeof(int), compare);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num);
		printf("%d ", binary_search(card, num, n));
	}
	printf("\n");
	return (0);
}
