#include <stdio.h>
#include <stdlib.h>

int	cards[500001];

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	binary_upper_search(int num, int start, int end)
{
	int	mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (cards[mid] == num && (mid - 1 < 0 || cards[mid - 1] < num))
			return (mid);
		else if (cards[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}

int	binary_lower_search(int num, int n, int start, int end)
{
	int	mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (cards[mid] == num && (mid + 1 >= n || cards[mid + 1] > num))
			return (mid);
		else if (cards[mid] > num)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (-1);
}

int	main(void)
{
	int	n, m, check, start, end;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &cards[i]);

	qsort(cards, n, sizeof(int), compare);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &check);
		end = binary_lower_search(check, n, 0, n - 1);
		start = binary_upper_search(check, 0, n - 1);
	
		if (end > -1 && start > -1)
			printf("%d ", end - start + 1);
		else
			printf("0 ");
	}
	printf("\n");
	return (0);
}
