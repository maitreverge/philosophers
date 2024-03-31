/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:18:56 by flverge           #+#    #+#             */
/*   Updated: 2024/03/31 20:45:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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