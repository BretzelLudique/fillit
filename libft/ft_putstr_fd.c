/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:48:06 by rcourtoi          #+#    #+#             */
/*   Updated: 2018/11/21 15:00:51 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t x;

	x = 0;
	if (!s)
		return ;
	while (s[x] != '\0')
	{
		ft_putchar_fd(s[x], fd);
		x++;
	}
}
