#include <stdio.h>
#include <stdlib.h>

typedef struct	coordinate
{
	int	x;
	int	y;
}	coor;

int	compare(const void *a, const void *b)
{
	coor	*num1 = (coor *)a;
	coor	*num2 = (coor *)b;

	if (num1->y < num2->y)
		return (-1);
	if (num1->y > num2->y)
		return (1);
	if (num1->x < num2->x)
		return (-1);
	if (num1->x > num2->x)
		return (1);
	return (0);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	coor	cr[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &cr[i].x, &cr[i].y);
	qsort(cr, n, sizeof(coor), compare);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", cr[i].x, cr[i].y);
	return (0);
}
