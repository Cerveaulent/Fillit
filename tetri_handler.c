/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetri_handler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/24 13:45:29 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 19:13:26 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*tetri_create(t_tetri **new_tetri)
{
	int i;

	i = 0;
	if (!(*new_tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	(*new_tetri)->letter = 'A';
	while (i < 4)
		bzero((*new_tetri)->te_grid[i++], 4);
	(*new_tetri)->next = NULL;
	return (*new_tetri);
}

void		tetri_add(t_tetri **l_tetri, t_tetri *new_tetri)
{
	t_tetri *tmp;

	tmp = *l_tetri;
	if (!(*l_tetri))
	{
		*l_tetri = new_tetri;
		return ;
	}
	while ((*l_tetri)->next)
		*l_tetri = (*l_tetri)->next;
	(*l_tetri)->next = new_tetri;
	new_tetri->letter = (*l_tetri)->letter + 1;
	*l_tetri = tmp;
}

void		tetri_destroy_list(t_tetri *addr_head)
{
	t_tetri *tmp;

	tmp = NULL;
	if (!(addr_head))
		return ;
	while (addr_head)
	{
		tmp = addr_head;
		addr_head = (addr_head)->next;
		free(tmp);
	}
	addr_head = NULL;
}
