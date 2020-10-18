/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcourtoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:21:46 by rcourtoi          #+#    #+#             */
/*   Updated: 2019/04/16 04:59:05 by rcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_pos
{
	char	**grid;
	int		*shapes;
	int		size;
	int		t;
	int		s;
	int		side;
}					t_pos;

int					solve_shit(t_pos *pos, int x, int y);
int					grid(t_pos *pos);
int					min_side(int nb);
int					*process_input(int s, char *buff);
void				display(char **tab);
int					place_t(t_pos *pos, int x, int y);
int					free_grid(t_pos *pos, int option);
int					check_input(int fd, char **buff);

#endif
