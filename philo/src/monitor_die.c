/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:18:56 by flverge           #+#    #+#             */
/*   Updated: 2024/03/31 20:55:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool philo_died(t_philo *philo)
{
	long ecoule;
	long t_to_die;

	if (get_bool(&philo->philo_mutex, &philo->is_philo_full))
		return false;
	
	ecoule = get_time(MILLISECOND) - get_sizet(&philo->philo_mutex, &philo->last_meal_time);

	t_to_die = philo->relink_pars.time2die;

	if (ecoule > t_to_die)
		return true;
	return false;
	
}

void *monitor_dinner(void *data)
{
	size_t i;
	t_pars *pars;

	pars = (t_pars *)data;

	while (!all_threads_running(&pars->mutex_pars, &pars->threads_running_nb, pars->nb_philos))
		; // wait for all the threads running before starting the dinner

	while (!simulation_over(pars))
	{
		i = 0;
		while (i < pars->nb_philos)
		{
			if (philo_died(pars->philos + i) && !simulation_over(pars))
			{
				set_bool(&pars->mutex_pars, &pars->is_diner_over, true);
				write_status(DIE, pars->philos + i);
			}
		}
		



		
	}
	return NULL;
}