#include <fdf.h>

/*
 * Similar to mlx_pixel_put but for an image. Image still won't be shown until we put the image to the window.
 */

void			img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WID && y >= 0 && y < LEN)
		*(int *)(img->data_addr + ((x + y * WID) * img->bpp)) = color;
}

/*
 * Draws a line between two given points on the image.
 */
void			draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	double		d[3];
	double		x;
	double		y;
	double		z;
	double		inc;

	d[0] = (p2.x - p1.x);
	d[1] = (p2.y - p1.y);
	d[2] = (p2.z - p1.z);
	inc = (fabs(d[0]) > fabs(d[1])) ? fabs(d[0]) : fabs(d[1]);
	x = p1.x;
	y = p1.y;
	z = p1.z;
	while (fabs(x - p2.x) >= 1 || fabs(y - p2.y) >= 1)
	{
		if (fdf->pulse == -1 || ((int)fdf->pulse == (int)z
			|| (int)fdf->pulse + fdf->maxz/2 == (int)z
			|| (int)fdf->pulse - fdf->maxz/2 == (int)z))
			img_pixel_put(fdf->img, (int)x, (int)y,
				color_select(fdf->color, z * 60));
		x += (d[0] / inc);
		y += (d[1] / inc);
		z += (d[2] / inc);
	}
}

/*
 * Draws lines between each point of the map.
 */
void			draw(t_fdf *fdf)
{
	int			i;
	int			j;

	i = 0;
	while (i < fdf->map->len)
	{
		j = 0;
		while (j < fdf->map->wid)
		{
			if (j < fdf->map->wid - 1)
				draw_line(fdf, project_point(fdf, fdf->map->points[i][j]),
					project_point(fdf, fdf->map->points[i][j + 1]));
			if (i < fdf->map->len - 1)
				draw_line(fdf, project_point(fdf, fdf->map->points[i][j]),
					project_point(fdf, fdf->map->points[i + 1][j]));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->ptr, 0, 0);
}
