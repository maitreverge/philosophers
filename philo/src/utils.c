/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:34 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 11:52:51 by flverge          ###   ########.fr       */
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

void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->a.write_mutex, NULL);
	pthread_mutex_init(&p->a.dead, NULL);
	pthread_mutex_init(&p->a.time_eat, NULL);
	pthread_mutex_init(&p->a.is_full, NULL);
}
