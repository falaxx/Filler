#include "filler.h"

int	main(void)
{
	t_f f;

	f.sm_x = 0;
	f.sm_y = 0;
	f.player = 1;
	first_read_fd(&f);
	f = init(&f);
	while(1)
	{
		f = read_fd(&f);
	// 	// f = algo
		ft_putnbr(13);
		ft_putchar(' ');
		ft_putnbr(15);
		ft_putchar('\n');
		// sleep(10);
	}
	return (0);
}
