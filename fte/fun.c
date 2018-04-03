#include "fdf.h"

int		ft_getnbr(char *str)
{
	int		ret;

	if (*str == '-')
		return (-ft_getnbr(str + 1));
	if (*str == '+')
		return (ft_getnbr(str + 1));
	ret = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret = ret + *str - '0';
		str++;
	}
	return (ret);
}

int		ft_count_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	*fdf_to_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		if (str[i] && ft_isdigit(str[i]) == 0)
			str[i] = ' ';
		i++;
	}
	return (str);
}

void	ft_count_line(t_mlx *fdf, int fd)
{
	char	*line;

	fdf->nbr_line = 0;
	while (get_next_line(fd, &line) == 1)
		(fdf->nbr_line)++;
	close(fd);
}