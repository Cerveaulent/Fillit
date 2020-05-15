/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetri_check.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 18:24:47 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 01:03:18 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	count_sharp(t_tetri *tetri)
{
	int i;
	int j;
	int count;

	j = -1;
	count = 0;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (tetri->te_grid[j][i] == '#')
				count++;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

static int	rec_tetri(t_tetri *tetri, int i, int j)
{
	int count;

	count = 1;
	tetri->te_grid[j][i] = tetri->letter;
	if (j != 3 && tetri->te_grid[j + 1][i] == '#')
		count += rec_tetri(tetri, i, j + 1);
	if (j != 0 && tetri->te_grid[j - 1][i] == '#')
		count += rec_tetri(tetri, i, j - 1);
	if (i != 3 && tetri->te_grid[j][i + 1] == '#')
		count += rec_tetri(tetri, i + 1, j);
	if (i != 0 && tetri->te_grid[j][i - 1] == '#')
		count += rec_tetri(tetri, i - 1, j);
	return (count);
}

int			tetri_check(t_tetri *tetri)
{
	int i;
	int j;

	if (!tetri)
	{
		return (100);
	}
	if (!count_sharp(tetri))
	{
		return (0);
	}
	find_first(tetri->te_grid, &i, &j, '#');
	if (rec_tetri(tetri, i, j) == 4)
		return (tetri_check(tetri->next));
	else
		return (0);
}
