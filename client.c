/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:18:11 by zsidki            #+#    #+#             */
/*   Updated: 2021/06/03 21:39:09 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	send_bits(int pid, unsigned char c)
{
	unsigned char	a;
	char			bit;

	bit = 0;
	a = 128;
	while (bit < 8)
	{
		if (c & a)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (write (2, "Invalid PID!\n", 14));
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (write (2, "Invalid PID!\n", 14));
		}
		usleep(70);
		c = c << 1;
		bit++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
	{
		write(2, "Invalid Arguments!\n", 19);
		return (1);
	}
	if (atoi(argv[1]) < 0)
	{
		write(2, "Invalid PID!\n", 13);
		return (1);
	}
	i = -1;
	while (argv[2][++i])
	{
		if (send_bits(atoi(argv[1]), argv[2][i]) != 0)
			return (1);
	}
}
