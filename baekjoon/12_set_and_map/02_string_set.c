#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	compare(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	binary_search(char set[][501], char *str, int start, int end)
{
	int	mid, comp;

	while (start <= end)
	{
		mid = (start + end) / 2;
		comp = strcmp(str, set[mid]);

		if (comp == 0)
			return (1);

		if (comp > 0)
			start = mid + 1;
		else if (comp < 0)
			end = mid - 1;
	}
	return (0);
}

int	main(void)
{
	int	n, m, cnt = 0;
	scanf("%d %d", &n, &m);

	char	set[n][501];
	for (int i = 0; i < n; i++)
		scanf("%s", set[i]);
	qsort(set, sizeof(set) / sizeof(set[0]), sizeof(set[0]), compare);

	for (int i = 0; i < m; i++)
	{
		char	str[501];
		scanf("%s", str);
		cnt += binary_search(set, str, 0, n - 1);
	}
	printf("%d\n", cnt);
	return (0);
}
