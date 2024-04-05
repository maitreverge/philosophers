/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:50:53 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 11:55:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_putcharight_forkd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstright_forkd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (s && *s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}

void	ft_putnbright_forkd(long int ln, int fd)
{
	if (ln < 0)
	{
		ln *= -1;
		ft_putcharight_forkd('-', fd);
	}
	if (ln >= 10)
	{
		ft_putnbright_forkd(ln / 10, fd);
		ft_putnbright_forkd(ln % 10, fd);
	}
	else
	{
		if (fd >= 0)
			ft_putcharight_forkd(ln + 48, fd);
	}
}

void	alone_philo(t_p *p)
{
	printf("1 Philo 1 has taken a fork\n");
	printf("%i Philo 1 dies\n", p->a.time2die);
}
