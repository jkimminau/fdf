#include <fdf.h>

/*
 * Macros for keys.
 */

#define KEY_ESC 53
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_UP 125
#define KEY_DOWN 126
#define KEY_SPACE 49
#define KEY_W 13
#define KEY_S 1
#define KEY_P 35

int		mouse_move(int x, int y, t_fdf *fdf)
{
	if (x >= 0 && x < WID && y >= 0 && y < LEN)
	{
		if (x != fdf->mx)
		{
			fdf->cam->x += x - fdf->mx;
			fdf->mx = x;
		}
		if (y != fdf->my)
		{
			fdf->cam->y += y - fdf->my;
			fdf->my = y;
		}
	}
	return (0);
}

/*
 * Handler for every time any key on the keyboard is pressed.
 *
 *   Escape frees the fdf struct and ends the program.
 *   Left/Right will rotate the view horizontally.
 *   Up/Down will rotate the view vertically.
 *   Space toggles autorotation.
 *   W/S will change the height factor.
 *   P toggles pulse mode.
 */
int		handle_keys(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
	{
		free_all(fdf);
		exit(0);
	}
	if (key == KEY_LEFT || key == KEY_RIGHT)
		fdf->map->x += fdf->map->wid * ((key == KEY_LEFT) ? -1 : 1);
	if (key == KEY_UP || key == KEY_DOWN)
		fdf->map->y += fdf->map->len * ((key == KEY_DOWN) ? -1 : 1);
	if (key == KEY_SPACE)
		fdf->autorotate = (fdf->autorotate == 0) ? 1 : 0;
	if (key == KEY_W)
		fdf->z++;
	if (key == KEY_S && fdf->z > 0)
		fdf->z--;
	if (key == KEY_P)
		fdf->pulse = (fdf->pulse < 0) ? 0 : -1;
	return (0);
}
