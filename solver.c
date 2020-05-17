/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 15:39:09 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/05/17 17:12:33 by charles     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "tetri_handler.h"

static int		create_grid(char ***grid, int size)
{
	int		i_col;

	i_col = -1;
	if (!(*grid = (char **)malloc(sizeof(char *) * size)))
		return (-1);
	while (++i_col < size)
	{
		if (!((*grid)[i_col] = (char *)malloc(sizeof(char) * size)))
		{
			free(*grid);
			return (-2);
		}
		ft_memset((*grid)[i_col], '.', size);
	}
	return (0);
}

static	int		calc_closest_sqr(int nb_sharp)
{
	int cl_sqr;

	cl_sqr = 2;
	while ((cl_sqr * cl_sqr) < nb_sharp)
		cl_sqr++;
	return (cl_sqr);
}

static int		calc_min_size(t_tetri *head)
{
	int		nb_sharp;
	int		ret;
	t_tetri	*tmp;

	nb_sharp = 0;
	ret = 0;
	tmp = head;
	while (tmp)
	{
		nb_sharp++;
		tmp = tmp->next;
	}
	nb_sharp *= 4;
	ret = calc_closest_sqr(nb_sharp);
	return (ret);
}

static void		free_sol(int size, char ***sol)
{
	int incr;

	incr = -1;
	while (++incr < size)
		ft_strdel((*sol + incr));
	free(*sol);
}

void			solve(char ***sol, t_tetri *head)
{
	int		size;

	size = calc_min_size(head);
	if (create_grid(sol, size) != 0)
	{
		ft_putendl("error");
		tetri_destroy_list(head);
		exit(0);
	}
	while (!(sol_recursive(size, sol, head)))
	{
		free_sol(size++, sol);
		if (create_grid(sol, size) != 0)
		{
			tetri_destroy_list(head);
			exit(0);
		}
	}
	free_sol(size, sol);
}
