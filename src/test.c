
#include "../fract_ol.h"

int	test(int keycode, t_a *arg)
{
	if (keycode == 65307)
		mlx_destroy_window(arg->mlx, arg->wdw);
	if (keycode == 119)
		printf("W\n");
	return (0);
}

int	pseudo_main(void)
{
	t_a	arg;

	arg.mlx = mlx_init();
	arg.wdw = mlx_new_window(arg.mlx, 1920, 1080, "Hello world!");
	mlx_hook(arg.wdw, 2, 1L<<0, test, &arg);
	mlx_loop(arg.mlx);
	return (0);
}
