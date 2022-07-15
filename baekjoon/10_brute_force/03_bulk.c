#include <stdio.h>

struct infor {
	int	h;
	int	w;
	int	o;
};

void	compare(struct infor person[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (person[i].w > person[j].w && person[i].h > person[j].h)
				person[j].o++;
			else if (person[i].w < person[j].w && person[i].h < person[j].h)
				person[i].o++;
		}
	}
}

int	main(void)
{
	int	n;

	scanf("%d", &n);

	struct infor	person[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &person[i].w, &person[i].h);
		person[i].o = 1;
	}
	compare(person, n);
	for (int i = 0; i < n; i++)
		printf("%d ", person[i].o);
	printf("\n");
	return (0);
}
