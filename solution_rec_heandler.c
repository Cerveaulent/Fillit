/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solution_rec_heandler.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 17:04:34 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 03:57:55 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	rm_tetri(int size, char ***sol, char c)
{
	int		i;
	int		j;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			if ((*sol)[j][i] == c)
				(*sol)[j][i] = '.';
	}
	return (0);
}

static void	get_poses(t_tetri *tetri, t_point prems, t_point all[3])
{
	int	i;
	int j;
	int index;

	j = prems.y - 1;
	i = prems.x;
	index = 0;
	while (++j < 4 && index < 3)
	{
		while (++i < 4 && index < 3)
			if (tetri->te_grid[j][i] == tetri->letter)
				all[index++] = (t_point){.x = i - prems.x, .y = j - prems.y};
		i = -1;
	}
}

static int	pos_tetri(int size, char ***sol, t_point pos, t_tetri *tetri)
{
	t_point	prems;
	int		i;
	t_point	all[3];

	i = -1;
	if ((*sol)[pos.y][pos.x] != '.')
		return (0);
	find_first(tetri->te_grid, &(prems.x), &(prems.y), tetri->letter);
	get_poses(tetri, prems, all);
	(*sol)[pos.y][pos.x] = tetri->letter;
	while (++i < 3)
		if (0 <= pos.y + all[i].y && pos.y + all[i].y < size &&
		0 <= pos.x + all[i].x && pos.x + all[i].x < size)
		{
			if ((*sol)[pos.y + all[i].y][pos.x + all[i].x] == '.')
				(*sol)[pos.y + all[i].y][pos.x + all[i].x] = tetri->letter;
			else
				return (rm_tetri(size, sol, tetri->letter));
		}
		else
			return (rm_tetri(size, sol, tetri->letter));
	return (1);
}

static int	print_map(char ***sol, int size)
{
	int		incr;

	incr = -1;
	while (++incr < size && *sol)
	{
		write(1, ((*sol)[incr]), size);
		ft_putchar('\n');
		ft_strdel(&((*sol)[incr]));
	}
	return (1);
}

int			sol_recursive(int size, char ***sol, t_tetri *head)
{
	int		i;
	int		j;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
			if (pos_tetri(size, sol, (t_point){.x = i, .y = j}, head))
			{
				if (!head->next)
					return (print_map(sol, size));
				else if (sol_recursive(size, sol, head->next) == 1)
					return (1);
				else
					rm_tetri(size, sol, head->letter);
			}
	}
	return (0);
}
