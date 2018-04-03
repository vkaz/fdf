
#include "fdf.h"

int		coord_x(t_mlx *fdf, int x, int y)
{
	return (fdf->startx - (fdf->scalx * y) + (fdf->scalx * x));
}

int		coord_y(t_mlx *fdf, int x, int y, int z)
{
	if (z > 30000)
		z = 30000;
	if (z < -30000)
		z = -30000;
	return (fdf->starty + ((fdf->scaly) * x) + ((fdf->scaly) * y) - (z * 2));
}

void	draw_y(t_mlx *fdf)
{
	int			i; 
	int			j;

	i = 0;
	while (i < fdf->nbr_line)
	{
		j = 0;
		while (j < (fdf->nbr_split[i] - 1))
		{
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->nbr[i][j]);
			j++;
			fdf->x2 = coord_x(fdf, j, i);
			fdf->y2 = coord_y(fdf, j, i, fdf->nbr[i][j]);
			bh_dispatch(fdf);
		}
		i++;
	}
}

void	draw_x(t_mlx *fdf)
{
	int			i;
	int			j;

	i = 0;
	while (i < (fdf->nbr_line - 1))
	{
		j = 0;
		while (j < fdf->nbr_split[i] && (fdf->nbr_split[i + 1] - j) > 0)
		{
			fdf->x1 = coord_x(fdf, j, i);
			fdf->y1 = coord_y(fdf, j, i, fdf->nbr[i][j]);
			fdf->x2 = coord_x(fdf, j, i + 1);
			fdf->y2 = coord_y(fdf, j, i + 1, fdf->nbr[i + 1][j]);
			bh_dispatch(fdf);
			j++;
		}
		i++;
	}
}