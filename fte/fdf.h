/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:27:59 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/03/22 13:28:00 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H 
# define FDF_H

#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				**nbr;
	int				nbr_line;
	int				*nbr_split;
	int				a;
	int				scalx;
	int				scaly;
	int				startx;
	int				x1;
	int				starty;
	char			**split;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				i;
	int				j;
	int				k;
	char			*line;
	char			*line_copy;
	int				incx;
	int				incy;
	int 			delx;
	int 			dely;
}					t_mlx;

typedef struct 	s_dob
{
	double 		dx;
	double 		dy;
	double		d;
	double		d1;
	double		d2;
	double 		s1;
	double		s2;
	double		sx;
}				t_dob;


void	draw(t_mlx *fdf);
int		ft_getnbr(char *str);
int		ft_count_split(char **split);
char	*fdf_to_space(char *str);
void	ft_count_line(t_mlx *fdf, int fd);
void	read_file(t_mlx *fdf, int fd);
void	draw_y(t_mlx *fdf);
void	draw_x(t_mlx *fdf);
void	closing(t_mlx *param);
void	freed(char **str);

#endif
