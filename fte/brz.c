#include "fdf.h"

void 		pos(t_mlx *fdf, t_dob *dob)
{
	int 	i;

	i = 0;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
	while (i < dob->dx)
		{
			while (dob->d2 >= 0)
			{
				if (dob->d1 == 1)
					fdf->x1 = fdf->x1+ dob->s1;
				else
					fdf->y1 = fdf->y1 + dob->s2;
				dob->d2 = dob->d2 - (2 * dob->dx);
			}
			if (dob->d1 == 1)
				fdf->y1 = fdf->y1 + dob->s2;
			else
				fdf->x1 = fdf->x1 + dob->s1;
			dob->d2 = dob->d2 + (2 * dob->dy);
			i++;
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
		}
}

void 		neg(t_mlx *fdf, t_dob *dob)
{
	int 	i;

	i = 0;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
	while (i < dob->dy)
		{
			while (dob->d1 >= 0)
			{
				if (dob->d2 == 1)
					fdf->y1 = fdf->y1 + dob->s2;
				else
					fdf->x1 = fdf->x1 + dob->s1;
				dob->d1 = dob->d1 - (2 * dob->dy);
			}
			if (dob->d2 == 1)
				fdf->x1 = fdf->x1 + dob->s1;
			else
				fdf->y1 = fdf->y1 + dob->s2;
			dob->d1 = dob->d1 + (2 * dob->dx);
			i++;
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
		}
}

void	draw(t_mlx *fdf)
{
	t_dob			dob;

	fdf->x2 += fdf->delx;
	fdf->y2 += fdf->dely;
	fdf->x1 += fdf->delx;
	fdf->y1 += fdf->dely;
	fdf->dx = (fdf->x2 - fdf->x1);
	fdf->dy = (fdf->y2 - fdf->y1);
	dob.dx = abs(fdf->x2 - fdf->x1);
	dob.dy = abs(fdf->y2 - fdf->y1);
	dob.s1 = (fdf->x2 > fdf->x1 ? 1 : -1);
	dob.s2 = (fdf->y2 > fdf->y1 ? 1 : -1);
	dob.d2 = (2 * dob.dy) - dob.dx;
	if (dob.dy < dob.dx)
		pos(fdf, &dob);
	else
		neg(fdf, &dob);
}

void		freed(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}
