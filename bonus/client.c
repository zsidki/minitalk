/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:18:11 by zsidki            #+#    #+#             */
/*   Updated: 2021/05/31 16:20:25 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minitalk.h"

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

static	int	ft_error(int argc, char *argv[])
{
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
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*pid;
	char	*s;
	char	*message;

	if (ft_error(argc, argv))
		return (1);
	i = -1;
	pid = ft_itoa(getpid());
	message = ft_strjoin(pid, "> ");
	free(pid);
	s = message;
	message = ft_strjoin(message, argv[2]);
	free(s);
	s = message;
	message = ft_strjoin(message, "\n");
	free(s);
	while (message[++i])
	{
		if (send_bits(atoi(argv[1]), message[i]) != 0)
			return (1);
	}
	if (message)
		free(message);
	return (0);
}
