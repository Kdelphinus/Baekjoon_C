#include <unistd.h>

int	main(void)
{
	write(1, "강한친구 대한육군", 25);
	write(1, "\n", 1);
	write(1, "강한친구 대한육군", 25);
	return (0);
}
