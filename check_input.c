/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 01:59:42 by rcourtoi          #+#    #+#             */
/*   Updated: 2019/04/16 04:01:35 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_sharp(char *str)
{
	int i;
	int sharp;

	i = 0;
	sharp = 0;
	while (str[i])
	{
		if (str[i] == '#')
			sharp++;
		if (i % 21 == 19)
		{
			if (sharp == 4)
				sharp = 0;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_input(int fd, char **buff)
{
	int	rd;
	int	x;

	rd = read(fd, *buff, 546);
	if (rd < 20 || rd > 545 || (rd + 1) % 21)
		return (0);
	(*buff)[rd] = '\0';
	x = -1;
	while (++x < rd)
	{
		if (((x % 21) + 1) % 5 && (x + 1) % 21
			&& (*buff)[x] != '.' && (*buff)[x] != '#')
			return (0);
		if (((x % 21) + 1) % 5 == 0 && (*buff)[x] != '\n')
			return (0);
		if ((x + 1) % 21 == 0 && x < rd && (*buff)[x] != '\n')
			return (0);
	}
	if (!(count_sharp(*buff)))
		return (0);
	return ((rd + 1) / 21);
}
