/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:34 by flverge           #+#    #+#             */
/*   Updated: 2024/03/31 20:37:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '+')
		return (true);
	return (false);
}

void	custom_exit(char *s)
{
	printf(RED"⛔ %s ⛔\n"RESET, s);
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
		pthread_mutex_init(&mutex, NULL);
	else if (code == LOCK)
		pthread_mutex_lock(&mutex);
	else if (code == UNLOCK)
		pthread_mutex_unlock(&mutex);
	else // DESTROY
		pthread_mutex_destroy(&mutex);
}

void set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	ft_mutex(LOCK, mutex);
	*dest = value;
	ft_mutex(UNLOCK, mutex);
}

bool get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool result;
	ft_mutex(LOCK, mutex);
	result = *value;
	ft_mutex(UNLOCK, mutex);
	return value;
}


void set_sizet(pthread_mutex_t *mutex, size_t *dest, size_t value)
{
	ft_mutex(LOCK, mutex);
	*dest = value;
	ft_mutex(UNLOCK, mutex);
}

size_t get_sizet(pthread_mutex_t *mutex, size_t *value)
{
	size_t result;
	ft_mutex(LOCK, mutex);
	result = *value;
	ft_mutex(UNLOCK, mutex);
	return value;
}

bool simulation_over(t_pars *pars)
{
	return (get_bool(&pars->mutex_pars, &pars->is_diner_over));
}


bool all_threads_running(pthread_mutex_t *mutex, size_t *threads, size_t philo_nb)
{
	bool result;

	result = false;

	ft_mutex(LOCK, mutex);

	if (*threads == philo_nb)
		result = true;

	ft_mutex(UNLOCK, mutex);
	
	return (result);
}