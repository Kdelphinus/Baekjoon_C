#include <stdio.h>
#include <stdlib.h>

int	compare(const void *a, const void *b)
{
	int	num1 = *(int *)a;
	int	num2 = *(int *)b;

	if (num1 < num2)
		return (-1);
	if (num1 > num2)
		return (1);
	return (0);
}

int	main(void)
{
	int	n;
	scanf("%d", &n);

	int	numbers[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &numbers[i]);

	qsort(numbers, sizeof(numbers) / sizeof(int), sizeof(int), compare);

	for (int i = 0; i < n; i++)
		printf("%d\n", numbers[i]);

	return (0);
}
