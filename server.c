/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:02:56 by zsidki            #+#    #+#             */
/*   Updated: 2021/05/30 22:08:37 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static void	set_bit(unsigned char bit)
{
	static unsigned char	c = 0;
	static int				bits = 0;

	c = c << 1;
	c |= bit;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

static void	bitzero(int a)
{
	a = 0;
	set_bit(0);
}

static void	bitone(int a)
{
	a = 0;
	set_bit(1);
}

int	main(void)
{
	signal(SIGUSR1, bitzero);
	signal(SIGUSR2, bitone);
	printf("%d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
