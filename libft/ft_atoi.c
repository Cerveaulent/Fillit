/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 18:19:01 by ccantin      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 01:43:27 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int neg;
	int res;

	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\r'
		|| *str == '\f' || *str == ' ')
		str++;
	neg = (*str == '-') ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	while (*str && ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	return (neg * res);
}
