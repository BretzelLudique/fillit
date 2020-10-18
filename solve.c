/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 05:12:41 by rcourtoi          #+#    #+#             */
/*   Updated: 2019/04/16 04:45:32 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "shapes.h"

void	remove_t(t_pos *pos, int x, int y)
{
	int i;

	i = 0;
	pos->grid[y][x] = '.';
	while (i < 3)
	{
		if (!(g_shape[pos->t][i][1] + y < 0
					|| g_shape[pos->t][i][1] + y >= pos->side
					|| g_shape[pos->t][i][0] + x >= pos->side
					|| g_shape[pos->t][i][0] + x < 0)
				&& (pos->grid[g_shape[pos->t][i][1] + y]
					[g_shape[pos->t][i][0] + x]
					== pos->s + 65))
			pos->grid[g_shape[pos->t][i][1] + y]
				[g_shape[pos->t][i][0] + x] = '.';
		i++;
	}
}

int		place_t(t_pos *pos, int x, int y)
{
	int i;

	i = 0;
	if (pos->grid[y][x] == '.')
		pos->grid[y][x] = pos->s + 65;
	else
		return (0);
	while (i < 3)
	{
		if (g_shape[pos->t][i][1] + y < 0
				|| g_shape[pos->t][i][1] + y >= pos->side
	|| g_shape[pos->t][i][0] + x >= pos->side || g_shape[pos->t][i][0] + x < 0)
			break ;
		if (pos->grid[g_shape[pos->t][i][1] + y]
				[g_shape[pos->t][i][0] + x] == '.')
			pos->grid[g_shape[pos->t][i][1] + y]
				[g_shape[pos->t][i][0] + x] = pos->s + 65;
		else
			break ;
		i++;
	}
	if (i == 3)
		return (1);
	remove_t(pos, x, y);
	return (0);
}

int		next(t_pos *pos, int *xmax, int *ymax)
{
	int x;
	int y;

	y = 0;
	while (y < pos->side)
	{
		x = 0;
		while (x < pos->side)
		{
			if (pos->grid[y][x] == '.'
					&& ((x > *xmax && y >= *ymax) || y > *ymax))
			{
				*xmax = x;
				*ymax = y;
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int		solve_shit(t_pos *pos, int x, int y)
{
	if (pos->s < pos->size)
		pos->t = pos->shapes[pos->s];
	if (pos->s == pos->size)
		return (1);
	while (next(pos, &x, &y))
	{
		if (place_t(pos, x, y))
		{
			pos->s++;
			if (solve_shit(pos, -1, 0))
				return (1);
			pos->s--;
			pos->t = pos->shapes[pos->s];
			remove_t(pos, x, y);
		}
	}
	return (0);
}
