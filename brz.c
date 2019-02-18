/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:14:43 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/04/12 13:14:46 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		pos(t_mlx *fdf)
{
	int		i;

	i = 0;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
	while (i < fdf->dx)
	{
		while (fdf->d2 >= 0)
		{
			if (fdf->d1 == 1)
				fdf->x1 = fdf->x1 + fdf->s1;
			else
				fdf->y1 = fdf->y1 + fdf->s2;
			fdf->d2 = fdf->d2 - (2 * fdf->dx);
		}
		if (fdf->d1 == 1)
			fdf->y1 = fdf->y1 + fdf->s2;
		else
			fdf->x1 = fdf->x1 + fdf->s1;
		fdf->d2 = fdf->d2 + (2 * fdf->dy);
		i++;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
	}
}

static void		neg(t_mlx *fdf)
{
	int		i;

	i = 0;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
	while (i < fdf->dy)
	{
		while (fdf->d1 >= 0)
		{
			if (fdf->d2 == 1)
				fdf->y1 = fdf->y1 + fdf->s2;
			else
				fdf->x1 = fdf->x1 + fdf->s1;
			fdf->d1 = fdf->d1 - (2 * fdf->dy);
		}
		if (fdf->d2 == 1)
			fdf->x1 = fdf->x1 + fdf->s1;
		else
			fdf->y1 = fdf->y1 + fdf->s2;
		fdf->d1 = fdf->d1 + (2 * fdf->dx);
		i++;
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x1, fdf->y1, 0xFFFFFF);
	}
}

void			draw(t_mlx *fdf)
{
	fdf->x2 += fdf->delx;
	fdf->y2 += fdf->dely;
	fdf->x1 += fdf->delx;
	fdf->y1 += fdf->dely;
	fdf->dx = (fdf->x2 - fdf->x1);
	fdf->dy = (fdf->y2 - fdf->y1);
	fdf->dx = abs(fdf->x2 - fdf->x1);
	fdf->dy = abs(fdf->y2 - fdf->y1);
	fdf->s1 = (fdf->x2 > fdf->x1 ? 1 : -1);
	fdf->s2 = (fdf->y2 > fdf->y1 ? 1 : -1);
	fdf->d2 = (2 * fdf->dy) - fdf->dx;
	if (fdf->dy < fdf->dx)
		pos(fdf);
	else
		neg(fdf);
}

void			doing(t_mlx *fdf)
{
	fdf->i = 0;
	fdf->line_copy = fdf->line;
	fdf->line = fdf_space(fdf->line);
	fdf->split = ft_strsplit(fdf->line, ' ');
	fdf->nbr_split[fdf->k] = ft_count_split(fdf->split);
}

void			freed(char **str)
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
