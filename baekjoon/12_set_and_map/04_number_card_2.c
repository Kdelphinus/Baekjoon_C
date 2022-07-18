#include <stdio.h>
#include <stdlib.h>

int	cards[500001];
int	check[500001];

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	binary_search(int num, int cnt, int start, int end)
{
	int	mid, result;

	if (start > end)
		return cnt;
	
	mid = (start + end) / 2;

	if (cards[mid] > num)
		return (binary_search(num, cnt, start, mid - 1));
	else if (cards[mid] < num)
		return (binary_search(num, cnt, mid + 1, end));
	else
	{
		result = binary_search(num, cnt, start, mid - 1);
		result += binary_search(num, cnt, mid + 1, end);
		result++;
	}
	return (result);
}

int	main(void)
{
	int	n, m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &cards[i]);

	qsort(cards, n, sizeof(int), compare);

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &check[i]);

	for (int i = 0; i < m; i++)
		printf("%d ", binary_search(check[i], 0, 0, n - 1));
	printf("\n");
	return (0);
}
