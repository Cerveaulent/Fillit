/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: charles <charles@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 22:55:21 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2020/05/17 17:11:30 by charles     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "tetri_handler.h"

int		check_file(char **argv)
{
	char	buff[700];
	int		ret;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buff, 700);
	if (ret > 545)
	{
		close(fd);
		return (0);
	}
	if (ret > 0 && ((buff[ret - 1] == '\n' && buff[ret - 2] == '\n')
			|| buff[ret - 1] != '\n'))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	t_tetri	*l_tetri;
	int		fd;
	char	**sol;

	l_tetri = NULL;
	sol = NULL;
	if (argc != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (-1);
	}
	if (!check_file(argv) || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	if (!(l_tetri = main_parsing(fd)))
		return (-1);
	solve(&sol, l_tetri);
	tetri_destroy_list(l_tetri);
	close(fd);
	return (0);
}
