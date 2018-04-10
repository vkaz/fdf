/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:14:57 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/02/27 17:14:58 by vkaznodi         ###   ########.fr       */
/* ************************************************************************** */
#include "fdf.h"

int		get_hook(t_mlx *fdf)
{
	//printf("Control by arrows\n");
	draw_y(fdf);
	draw_x(fdf);
	return (1);
}

int		key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
		exit(1);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	if (keycode == 123)
		param->delx -= 10;
	if (keycode == 126)
		param->dely -= 10;
	if (keycode == 124)
		param->delx += 10;
	if (keycode == 125)
		param->dely += 10;
	if (keycode == 78)
	{
		param->scalx -= 1;
		param->scaly -= 1;
	}
	if (keycode == 69)
	{
		param->scalx += 1;
		param->scaly += 1;
	}
	get_hook(param);
	return (0);
}

void	read_file(t_mlx *fdf, int fd)
{
	if (!(fdf->nbr = (int **)malloc(sizeof(int *) * fdf->nbr_line)) ||
			!(fdf->nbr_split = (int *)malloc(sizeof(int) * fdf->nbr_line)))
		exit(1);
	while (get_next_line(fd, &(fdf->line)) == 1)
	{
		if (fdf->line)
		{
			fdf->i = 0;
			fdf->line = fdf_to_space(fdf->line);
			fdf->split = ft_strsplit(fdf->line, ' ');
			fdf->nbr_split[fdf->k] = ft_count_split(fdf->split);
			if (!(fdf->nbr[fdf->j] = (int *)malloc(sizeof(int) *
							fdf->nbr_split[fdf->k])))
				exit(1);
			while (fdf->split[fdf->i])
			{
				fdf->nbr[fdf->j][fdf->i] = ft_getnbr(fdf->split[fdf->i]);
				(fdf->i)++;
			}
			free(fdf->split);
			(fdf->j)++;
			(fdf->k)++;
		}
	}
}
void	init(t_mlx *fdf)
{
	fdf->j = 0;
	fdf->k = 0;
	fdf->scalx = 20;
	fdf->scaly = 20;
	fdf->startx = 960;
	fdf->starty = 340;
	fdf->delx = 0;
	fdf->dely = 0;
	fdf->x1= 0;
	fdf->y1 = 0;
	fdf->x2 = 0;
	fdf->y2 = 0;
	fdf->dx = 0;
	fdf->dy = 0;
	fdf->i = 0;
	fdf->incx = 0;
	fdf->incy = 0;
	fdf->nbr[0][0] = 0;
}

int			main(int ac, char **av)
{
	t_mlx	fdf;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_count_line(&fdf, fd);
		fd = open(av[1], O_RDONLY);
		init(&fdf);
		read_file(&fdf, fd);
		close(fd);
		fdf.mlx_ptr = mlx_init();
		fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "FdF");
		get_hook(&fdf);
		mlx_key_hook(fdf.win_ptr, key_hook, &fdf);
		mlx_loop(fdf.mlx_ptr);
	}
	else
		ft_putendl("usage /fdf \"file\"");
	return (0);
}
