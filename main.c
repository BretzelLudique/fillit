/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 23:20:26 by rcourtoi          #+#    #+#             */
/*   Updated: 2019/04/16 05:18:22 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_grid(t_pos *pos, int option)
{
	int i;

	if (pos->grid != NULL)
	{
		i = 0;
		while (pos->grid[i])
		{
			ft_memdel((void**)&((pos->grid)[i]));
			i++;
		}
		free(pos->grid);
	}
	if (option)
		ft_memdel((void**)&(pos->shapes));
	return (1);
}

int		grid(t_pos *pos)
{
	int i;

	i = 0;
	if (pos->grid)
		free_grid(pos, 0);
	if (!(pos->grid = (char **)malloc(sizeof(char *) * (pos->side + 1))))
		return (0);
	while (i < pos->side)
	{
		if (!(pos->grid[i] = (char *)malloc(sizeof(char) * (pos->side + 1))))
			return (0);
		ft_memset(pos->grid[i], '.', pos->side);
		pos->grid[i][pos->side] = '\0';
		i++;
	}
	pos->grid[i] = NULL;
	return (1);
}

int		error(t_pos *pos, char *read_buff)
{
	free(read_buff);
	free_grid(pos, 1);
	ft_putendl("error");
	return (1);
}

int		wrong_args(t_pos *pos, char *read_buff)
{
	free(read_buff);
	free_grid(pos, 1);
	ft_putendl("usage: ./fillit source_file");
	return (0);
}

int		main(int ac, char **av)
{
	char	*read_buff;
	t_pos	pos;
	int		fd;

	ft_bzero(&pos, sizeof(t_pos));
	if (!(read_buff = ft_strnew(546)))
		return (error(&pos, read_buff));
	if (ac != 2)
		return (wrong_args(&pos, read_buff));
	fd = open(av[1], O_RDONLY);
	pos.size = check_input(fd, &read_buff);
	if ((fd < 0) || (pos.size == 0)
		|| ((pos.shapes = process_input(pos.size, read_buff)) == NULL))
		return (error(&pos, read_buff));
	pos.side = min_side(pos.size);
	grid(&pos);
	while (!solve_shit(&pos, -1, 0))
	{
		pos.side++;
		if (!grid(&pos))
			return (error(&pos, read_buff));
	}
	display(pos.grid);
	free_grid(&pos, 1);
	free(read_buff);
}
