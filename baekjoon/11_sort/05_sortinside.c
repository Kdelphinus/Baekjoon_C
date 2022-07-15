#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	compare(const void *a, const void *b)
{
	char n1 = *(char *)a;
	char n2 = *(char *)b;

	if (n1 < n2)
		return (1);
	if (n1 > n2)
		return (-1);
	return (0);
}

int	main(void)
{
	int		size;
	char	number[10];

	scanf("%s", number);
	size = strlen(number);

	qsort(number, size, sizeof(char), compare);
	for (int i = 0; i < size; i++)
		printf("%c", number[i]);
	printf("\n");
	return (0);
}
