/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_handler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/24 14:02:57 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 19:12:01 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "tetri_handler.h"

void	err_free(char **line, t_tetri *tetri, int fd)
{
	ft_putendl("error");
	ft_strdel(line);
	tetri_destroy_list(tetri);
	close(fd);
	exit(0);
}

int		free_tail(t_tetri *tail)
{
	free(tail);
	return (0);
}
