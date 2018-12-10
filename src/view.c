#include <fdf.h>
#include <stdio.h>

/*
 * Gives a 2D position for a point given the current view and its 3D position.
 *
 * Obviously this method is super ugly, I would highly recommed googling "orthographic projection" and using matrix multiplication instead.
 * Or you can just copy me like a dirty cheater lol.
 */



t_point		project_point(t_fdf *fdf, t_point p)
{
	t_point		pp;
	double		x;
	double		y;
	double		z;

	x = p.x;
	y = p.y;
	z = p.z;
	

	pp.x = fdf->map->x + (COS(fdf->cam->x) * (x - fdf->map->x)) + (z * SIN(fdf->cam->x) * fdf->z * COS(fdf->cam->y)) - (fdf->map->y * SIN(fdf->cam->y) * SIN(fdf->cam->x) * ((y - fdf->map->y) / fdf->map->y));
	pp.y = fdf->map->y + (COS(fdf->cam->y) * (y - fdf->map->y)) + (z * SIN(fdf->cam->y) * fdf->z);
	pp.z = p.z;

	return (pp);
}

/*
 * Color slider function. ;)
 */
int			color_select(int color, int num)
{
	color += num;
	color %= 1536;
	if (color >= 0 && color < 256)
		color = 0xFF0000 + (color << 8);
	else if (color >= 256 && color < 512)
		color = 0xFFFF00 - ((color % 256) << 16);
	else if (color >= 512 && color < 768)
		color = 0x00FF00 + ((color % 256));
	else if (color >= 512 && color < 1024)
		color = 0x00FFFF - ((color % 256) << 8);
	else if (color >= 512 && color < 1280)
		color = 0x0000FF + ((color % 256) << 16);
	else if (color >= 512 && color < 1536)
		color = 0xFF00FF - ((color % 256));
	return (color);
}
