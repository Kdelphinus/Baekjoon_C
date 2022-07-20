#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	tmp[1001];
char	str[1001];
char	**strs;

int	compare(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int	binary_search(char *tmp, int start, int end)
{
	int	mid, cmp;

	while (start <= end)
	{
		mid = (start + end) / 2;
		cmp = strcmp(tmp, strs[mid]);

		if (cmp == 0)
			return (0);
		else if (cmp > 0)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (1);
}

int	main(void)
{
	int	size, cnt = 0;

	scanf("%s", str);
	size = strlen(str);

	strs = (char **)malloc(sizeof(char *) * (500500 + 1));
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			strncpy(tmp, (str + i), j - i + 1);
			tmp[j - i + 2] = 0;
			strs[cnt] = (char *)malloc(sizeof(char) * (j - i + 2));
			if (cnt == 0)
				strs[cnt++] = strdup(tmp);
			else
			{
				if (binary_search(tmp, 0, cnt - 1))
					strs[cnt++] = strdup(tmp);
			}
			memset(tmp, 0, j - i + 1);
			qsort(strs, cnt, sizeof(strs[0]), compare);
		}
	}
	printf("%d\n", cnt);
	return (0);
}
