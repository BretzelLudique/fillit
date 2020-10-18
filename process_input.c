/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 06:00:43 by rcourtoi          #+#    #+#             */
/*   Updated: 2019/04/16 05:24:26 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "shapes.h"

int	test_shape(char **sqr, int x, int y)
{
	int i;
	int t;

	t = 0;
	while (t < 19)
	{
		i = 0;
		while (i < 3)
		{
			if ((g_shape[t][i][1] + y) > 3 || (g_shape[t][i][1] + y) < 0
					|| (g_shape[t][i][0] + x) > 3 || (g_shape[t][i][0] + x) < 0)
				break ;
			if (sqr[g_shape[t][i][1] + y][g_shape[t][i][0] + x] != '#')
			{
				i = 0;
				break ;
			}
			i++;
		}
		if (i == 3)
			return (t);
		t++;
	}
	return (-1);
}

int	first(char *buff)
{
	int x;

	x = 0;
	while (buff[x] != '#' && buff[x] != '\0')
	{
		x++;
	}
	if (buff[x] == '#')
		return (x);
	return (-1);
}

int	*free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free((void *)split[i]);
		split[i] = NULL;
		i++;
	}
	free((void *)split);
	split = NULL;
	return (0);
}

int	*process_input(int s, char *buff)
{
	int		*shapes;
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !(shapes = malloc(sizeof(int) * s)))
		return (NULL);
	if (!(split = ft_strsplit(buff, '\n')))
		return (NULL);
	while (i < s)
	{
		shapes[i] = test_shape(&split[i * 4],
				first(&buff[j]) % 5, first(&buff[j]) / 5);
		if (shapes[i] == -1)
		{
			free(shapes);
			return (free_split(split));
		}
		j += 21;
		i++;
	}
	free_split(split);
	return (shapes);
}
