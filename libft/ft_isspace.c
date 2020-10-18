/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 04:22:49 by rcourtoi          #+#    #+#             */
/*   Updated: 2018/11/12 04:29:34 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if (c == '\f' ||
			c == '\t' ||
			c == '\n' ||
			c == '\r' ||
			c == '\v' ||
			c == ' ')
		return (1);
	return (0);
}