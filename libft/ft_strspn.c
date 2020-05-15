/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strspn.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 14:39:45 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 01:48:57 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(char *charset, char *str)
{
	size_t nb;

	nb = 0;
	while (*charset)
		if (ft_strchr(str, *charset++))
			nb++;
	return (nb);
}
