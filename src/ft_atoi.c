/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:06:47 by zsidki            #+#    #+#             */
/*   Updated: 2021/05/31 16:30:30 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sgn;
	size_t	rsl;

	i = 0;
	sgn = 1;
	rsl = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rsl = rsl * 10 + str[i] - '0';
		if (rsl > 9223372036854775807 && sgn == -1)
			return (0);
		else if (rsl > 9223372036854775807 && sgn == 1)
			return (-1);
		i++;
	}
	return (rsl * sgn);
}
