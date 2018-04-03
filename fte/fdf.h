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

typedef struct s_mlx
{
	void	*mlx_ptr;
    void	*win_ptr;
    int		 	x1;
	int		 	x2;
	int		 	y1;
    int		 	y2;
    int 	    dx;
	int       	dy;
	int	    	d;
	int	    	d1;
	int	    	d2;
	int    	    s1;
    int 		s2;
    int			nbr_line;
    int			*nbr_split;
    int			scalx;
	int			scaly;
	int			startx;
	int			starty;
    char		**split;
    int         **nbr;
    char			*line;
    int				incx;
    int				incy;
    int				i;
	int				j;
    int				k;
    int             z;
    int             check;
    unsigned long	color;
    int             sx;
    int             sy;
}				t_mlx;

void	m_pos(t_mlx *fdf);
void	m_neg(t_mlx *fdf);
void	bh_dispatch(t_mlx *fdf);
int		ft_getnbr(char *str);
int		ft_count_split(char **split);
char	*fdf_to_space(char *str);
void	ft_count_line(t_mlx *fdf, int fd);
void	m_pos(t_mlx *fdf);
void	m_neg(t_mlx *fdf);
void	bh_dispatch(t_mlx *fdf);
void	read_file(t_mlx *fdf, int fd);
void	draw_y(t_mlx *fdf);
void	draw_x(t_mlx *fdf);

#endif
