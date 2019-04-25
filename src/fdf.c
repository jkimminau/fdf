#include <fdf.h>

# define PULSE_RATE 0.1
# define EVENT_WINDOW_CLOSE 17

int		handle_exit(t_fdf *fdf)
{
	free_all(fdf);
	exit(0);
	return (0);
}

/*
 * This function is called for every frame thta the image is rendered
 */

int		loop_events(t_fdf *fdf)
{
	if (fdf->autorotate)
	{
		fdf->cam->x += 0.25;
		fdf->cam->y += 0.125;
	}
	if (fdf->pulse != -1)
		fdf->pulse += PULSE_RATE;
	if ((int)fdf->pulse > fdf->maxz)
		fdf->pulse = PULSE_RATE;
	fdf->cam->x = (fdf->cam->x > 359) ? 0 : fdf->cam->x;
	fdf->cam->x += (fdf->cam->x < 0) ? 360 : 0;
	fdf->cam->y = (fdf->cam->y > 359) ? 0 : fdf->cam->y;
	fdf->cam->y += (fdf->cam->y < 0) ? 360 : 0;
	fdf->color = (fdf->color > 1536) ? 0 : fdf->color + 1.0;
	mlx_destroy_image(fdf->mlx, fdf->img->ptr);
	free(fdf->img);
	fdf->img = init_img(fdf->mlx);
	draw(fdf);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc < 2)
	{
		ft_putendl("usage: ./fdf [filename] ..");
		return (0);
	}
	fdf = init_fdf();
	if (parse(argv[1], fdf) == -1)
	{
		ft_putendl("error reading map file.");
		exit(0);
	}
	draw(fdf);
	mlx_hook(fdf->win, 6, 1L << 6, mouse_move, fdf);
	mlx_loop_hook(fdf->mlx, loop_events, fdf);
	mlx_hook(fdf->win, 2, 0, handle_keys, fdf);
	mlx_hook(fdf->win, EVENT_WINDOW_CLOSE, 0, handle_exit, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
