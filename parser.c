/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 17:15:31 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 15:34:13 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "tetri_handler.h"

static int			line_checker(char **line)
{
	int	i;

	i = 0;
	if (ft_strlen(*line) != 4)
		return (0);
	while (line[0][i])
	{
		if ((line[0][i] != '.' && line[0][i] != '#'))
			return (0);
		i++;
	}
	return (1);
}

static int			check_tetri_list(t_tetri *head)
{
	int		err_ret;
	int		nb_tetri;
	t_tetri	*tmp;

	nb_tetri = 0;
	err_ret = 0;
	tmp = head;
	while (tmp && nb_tetri < 26)
	{
		nb_tetri++;
		tmp = tmp->next;
	}
	if (nb_tetri > 26)
		return (err_ret);
	if ((err_ret = tetri_check(head)) != 100)
		return (err_ret);
	return (100);
}

static int			te_add(char **line, int it, t_tetri **head, t_tetri **tail)
{
	if (it % 5 && !(line_checker(line)))
		return (0);
	if (it % 5 == 1 && !(*tail = tetri_create(tail)))
		return (0);
	if ((it % 5) == 0 && *line[0] != '\0')
		return (0);
	if (it % 5 != 0)
		ft_memmove((*tail)->te_grid[(it % 5) - 1], *line, 5);
	if ((it % 5) == 0)
	{
		tetri_add(head, *tail);
		*tail = NULL;
	}
	return (1);
}

static int			fill_list(t_tetri **head, char **line, int fd)
{
	int		iter;
	t_tetri *tail;
	int		err_ret;
	char	*tmp;

	iter = 0;
	tmp = NULL;
	tail = NULL;
	while (((err_ret = gnl(fd, line)) > -1) && ++iter)
	{
		if (tmp)
			ft_strdel(&tmp);
		tmp = *line;
		if (!te_add(line, iter, head, &tail))
			return (free_tail(tail));
	}
	if ((iter + 1) % 5 != 0)
		return (free_tail(tail));
	ft_strdel(&tmp);
	tetri_add(head, tail);
	return (1);
}

t_tetri				*main_parsing(int fd)
{
	int		err_ret;
	t_tetri *head;
	char	*line;

	err_ret = 0;
	head = NULL;
	line = NULL;
	if (!(err_ret = fill_list(&head, &line, fd)))
	{
		err_free(&line, head, fd);
		return (NULL);
	}
	line = NULL;
	if (!(err_ret = check_tetri_list(head)))
	{
		err_free(&line, head, fd);
		return (NULL);
	}
	return (head);
}
