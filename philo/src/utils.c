/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:34 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 11:17:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '+')
		return (true);
	return (false);
}

void	custom_exit(char *str)
{
	printf(RED"⛔ %s ⛔\n"RESET, str);
	exit(EXIT_FAILURE);
}

void	*secure_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
		custom_exit("Malloc failed allocating memory");
	return (result);
}

void	ft_mutex(int code, pthread_mutex_t *mutex)
{
	if (code == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (code == LOCK)
		pthread_mutex_lock(mutex);
	else if (code == UNLOCK)
		pthread_mutex_unlock(mutex);
	else if (code == DESTROY)
		pthread_mutex_destroy(mutex);
}

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
