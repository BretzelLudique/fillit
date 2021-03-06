/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_side.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 00:19:47 by rcourtoi          #+#    #+#             */
/*   Updated: 2019/03/15 05:46:45 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		min_side(int nb)
{
	int i;

	i = 2;
	while (i * i < nb * 4)
	{
		i++;
	}
	return (i);
}
