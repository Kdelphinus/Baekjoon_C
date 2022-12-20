#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct	illustrated_book
{
	char	name[21];
	int	num;
}	pokemon_book;

int	compare_name(const void *a, const void *b)
{
	return (strcmp(((pokemon_book *)a)->name, ((pokemon_book *)b)->name));
}

int	compare_num(const void *a, const void *b)
{
	return (((pokemon_book *)a)->num - ((pokemon_book *)b)->num);
}

void	binary_search_num(pokemon_book pb_num[], int no, int start, int end)
{
	int	mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (pb_num[mid].num == no)
		{
			printf("%s\n", pb_num[mid].name);
			return ;
		}
		else if (pb_num[mid].num > no)
			end = mid - 1;
		else
			start = mid + 1;
	}
}

void	binary_search_name(pokemon_book pb_name[], char nam[], int start, int end)
{
	int	mid, cmp;

	while (start <= end)
	{
		mid = (start + end) / 2;
		cmp = strcmp(pb_name[mid].name, nam);

		if (cmp == 0)
		{
			printf("%d\n", pb_name[mid].num);
			return ;
		}
		else if (cmp > 0)
			end = mid - 1;
		else
			start = mid + 1;
	}
}

int	main(void)
{
	int	n, m;
	scanf("%d %d", &n, &m);

	pokemon_book	pb_num[n];
	pokemon_book	pb_name[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", pb_num[i].name);
		pb_num[i].num = i + 1;
		strcpy(pb_name[i].name, pb_num[i].name);
		pb_name[i].num = i + 1;
	}
	qsort(pb_num, n, sizeof(pokemon_book), compare_num);
	qsort(pb_name, n, sizeof(pokemon_book), compare_name);

	for (int i = 0; i < m; i++)
	{
		char	input[21];
		scanf("%s", input);

		if (isdigit(input[0]))
			binary_search_num(pb_num, atoi(input), 0, n - 1);
		else
			binary_search_name(pb_name, input, 0, n - 1);
	}
	return (0);
}
