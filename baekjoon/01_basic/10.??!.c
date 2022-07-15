#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *name;

	name = malloc(sizeof(char) * 51);
	scanf("%s", name);
	printf("%s\?\?!\n", name);
	return (0);
}
