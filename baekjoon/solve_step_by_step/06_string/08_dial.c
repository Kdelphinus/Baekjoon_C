#include <stdio.h>

int	main(void)
{
	int	time = 0;
	char	p_num[16];

	scanf("%s", p_num);
	for (int i = 0; p_num[i]; i++)
	{
		if (p_num[i] <= 'C')
			time += 3;
		else if (p_num[i] <= 'F')
			time += 4;
		else if (p_num[i] <= 'I')
			time += 5;
		else if (p_num[i] <= 'L')
			time += 6;
		else if (p_num[i] <= 'O')
			time += 7;
		else if (p_num[i] <= 'S')
			time += 8;
		else if (p_num[i] <= 'V')
			time += 9;
		else if (p_num[i] <= 'Z')
			time += 10;
	}
	printf("%d\n", time);
	return (0);
}
