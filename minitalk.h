/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsidki <zsidki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:33:29 by zsidki            #+#    #+#             */
/*   Updated: 2021/06/03 21:29:50 by zsidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>

int			ft_atoi(const char *str);
int			ft_putchar(char c);
void		ft_putnbr(int n);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);

#endif