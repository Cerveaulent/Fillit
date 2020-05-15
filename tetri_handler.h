/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetri_handler.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/24 13:45:39 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 19:12:30 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef TETRI_HANDLER_H
# define TETRI_HANDLER_H
# include "fillit.h"

/*
***			----***		tetri_handler.c		***----
*/

t_tetri				*tetri_create(t_tetri **new_tetri);
void				tetri_add(t_tetri **l_tetri, t_tetri *new_tetri);
int					tetri_check(t_tetri *tetri);
void				tetri_destroy_list(t_tetri *addr_head);

#endif
