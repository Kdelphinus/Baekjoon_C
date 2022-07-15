#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[101];
	int		alphabet[26];
	int		idx;

	scanf("%s", str);
	memset(alphabet, -1, sizeof(int) * 26);
	for (int i = 0; str[i]; i++)
	{
		idx = str[i] - 'a';
		if (alphabet[idx] == -1)
			alphabet[idx] = i;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", alphabet[i]);
	printf("\n");
	return (0);
}
