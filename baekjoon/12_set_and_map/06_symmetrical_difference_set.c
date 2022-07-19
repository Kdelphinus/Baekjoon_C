#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int	binary_search(int num[], int check, int start, int end)
{
	int	mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (num[mid] == check)
			return (0);
		else if (num[mid] > check)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (1);
}

int	main(void)
{
	int	a, b, cnt = 0;

	scanf("%d %d", &a, &b);

	int	num_a[a], num_b[b];
	
	for (int i = 0; i < a; i++)
		scanf("%d", &num_a[i]);

	qsort(num_a, a, sizeof(int), compare);

	for (int i = 0; i < b; i++)
		scanf("%d", &num_b[i]);

	qsort(num_b, b, sizeof(int), compare);

	for (int i = 0; i < a; i++)
		cnt += binary_search(num_b, num_a[i], 0, b - 1);
	for (int i = 0; i < b; i++)
		cnt += binary_search(num_a, num_b[i], 0, a - 1);
	printf("%d\n", cnt);

	return (0);
}
