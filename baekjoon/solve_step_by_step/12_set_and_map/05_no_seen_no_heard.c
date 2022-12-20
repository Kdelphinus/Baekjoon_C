#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	no_seen_no_heard[500001][21];

int	compare(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	binary_search(char no_heard[][21], char name[], int start, int end)
{
	int	mid, cmp;

	while (start <= end)
	{
		mid = (start + end) / 2;
		cmp = strcmp(no_heard[mid], name);

		if (cmp == 0)
			return (1);
		else if (cmp > 0)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (0);
}

int	main(void)
{
	int	n, m;
	int	tmp, cnt = 0;
	char	str[21];

	scanf("%d %d", &n, &m);
	char	no_heard[n][21];
	for (int i = 0; i < n; i++)
		scanf("%s", no_heard[i]);

	qsort(no_heard, n, sizeof(no_heard[0]), compare);

	for (int i = 0; i < m; i++)
	{
		scanf("%s", str);
		tmp = binary_search(no_heard, str, 0, n - 1);
		if (tmp)
		{
			strcpy(no_seen_no_heard[cnt], str);
			cnt++;
		}
	}

	qsort(no_seen_no_heard, cnt, sizeof(no_seen_no_heard[0]), compare);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%s\n", no_seen_no_heard[i]);
	return (0);
}
