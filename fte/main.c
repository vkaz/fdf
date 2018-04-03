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
	draw_y(fdf);
	draw_x(fdf);
	return (1);
}

int		key_hook(int keycode, void *param, t_mlx *cor)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	if (keycode == 126)
	{
		mlx_clear_window(cor->mlx_ptr, cor->win_ptr);
		cor->dx -= 100;
	}
	if (keycode == 123)
		cor->dx -= 100;
	if (keycode == 125)
		cor->dx += 100;
	if (keycode == 124)
		cor->dy += 100;
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
		mlx_expose_hook(fdf.win_ptr, get_hook, &fdf);
		mlx_key_hook(fdf.win_ptr, key_hook, &fdf);
		mlx_loop(fdf.mlx_ptr);
	}
	else
		ft_putendl("usage /fdf \"file\"");
	return (0);
}
