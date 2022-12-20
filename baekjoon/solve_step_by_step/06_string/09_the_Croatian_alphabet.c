#include <stdio.h>

int	main(void)
{
	int	idx = 0, cnt = 0;
	char	str[301];

	scanf("%s", str);
	while (str[idx])
	{
		cnt++;
		if (str[idx - 1] == 'c' && (str[idx] == '=' || str[idx] == '-'))
			cnt--;
		else if (str[idx - 1] == 'd' && str[idx] == '-')
			cnt--;
		else if ((str[idx - 1] == 'n' || str[idx - 1] == 'l') && str[idx] == 'j')
			cnt--;
		else if (str[idx - 1] == 's' && str[idx] == '=')
			cnt--;
		else if (str[idx - 1] == 'z' && str[idx] == '=')
		{
			if (idx > 1 && str[idx - 2] == 'd')
				cnt -= 2;
			else
				cnt--;
		}
		idx++;
	}
	printf("%d\n", cnt);
	return (0);
}
