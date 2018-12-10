#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/gnl/get_next_line.h"
# include <stdio.h>

# define WID 1000
# define LEN 800
# define DEG2RAD M_PI / 180
# define COS(x) cos(x * DEG2RAD)
# define SIN(x) sin(x * DEG2RAD)

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_map
{
	int			x;
	int			y;
	int			len;
	int			wid;
	t_point			**points;
}				t_map;

typedef struct	s_img
{
	void		*ptr;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef	struct	s_cam
{
	double			x;
	double			y;
}				t_cam;

/*
 * The main struct for this program. Holds smaller structs and a few options like autorotation and pulse.
 */
typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_cam		*cam;
	double		color;
	int		autorotate;
	int		z;
	int		maxz;
	int		mx;
	int		my;
	float		pulse;
}				t_fdf;

void			free_all(t_fdf *fdf);
t_point			new_point(int x, int y, int z);
t_img			*init_img(void *mlx);
t_fdf			*init_fdf();
int			mouse_move(int x, int y, t_fdf *fdf);
int			handle_keys(int key, t_fdf *fdf);
int			parse(char *filename, t_fdf *fdf);
void			img_pixel_put(t_img *img, int x, int y, int color);
void			draw(t_fdf *fdf);
t_point			project_point(t_fdf *fdf, t_point p);
int			color_select(int color, int num);

#endif
