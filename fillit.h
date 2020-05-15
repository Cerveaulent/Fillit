/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/04 09:16:03 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 19:11:41 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

typedef struct		s_tetri
{
	char			te_grid[4][5];
	char			letter;
	struct s_tetri	*next;
}					t_tetri;

typedef enum		e_error
{
	OPEN_ERROR = -1,
	INVALID_TETRI,
	INVALID_ARG,
	INVALID_CHAR,
	INVALID_CHAR_NUMB,
	NO_NEWLINE,
	ERR_GNL
}					t_error;

typedef struct		s_point
{
	int x;
	int y;
}					t_point;

/*
***			----***		parser.c			***----
*/

t_tetri				*main_parsing(int fd);

/*
***			----***		solver.c			***----
*/

void				solve(char ***sol, t_tetri *l_tetri);

/*
***			----***		error_handler.c		***----
*/

void				err_free(char **line, t_tetri *tetri, int fd);
int					free_tail(t_tetri *tail);

/*
*** 			----***		find_first.c		***----
*/

void				find_first(char grid[4][5], int *i, int *j, char c);

/*
*** 			----***		sol_rechandler.c		***----
*/

int					sol_recursive(int size, char ***sol, t_tetri *head);

#endif
