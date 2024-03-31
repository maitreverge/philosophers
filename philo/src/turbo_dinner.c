/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:35 by flverge           #+#    #+#             */
/*   Updated: 2024/03/31 20:18:28 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_one_philo(t_pars **pars)
{
	// code
}

void think (t_philo *philo)
{
	write_status(THINK, philo);
}

void eat(t_philo *philo)
{
	ft_mutex(LOCK, &philo->first_fork->fork);
	write_status(TAKE_FORK_1, philo);
	ft_mutex(LOCK, &philo->second_fork->fork);
	write_status(TAKE_FORK_2, philo);

	// set the last meal time
	set_sizet(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
	philo->nb_meals++;
	write_status(EAT, philo);
	precise_usleep(philo->relink_pars.time2eat, &philo->relink_pars);
	
	if ((philo->relink_pars.max_meals > 0) && (philo->nb_meals == philo->relink_pars.max_meals))
	{
		set_bool(&philo->philo_mutex, &philo->is_philo_full, true);
	}
	
	
	ft_mutex(UNLOCK, &philo->first_fork->fork);
	ft_mutex(UNLOCK, &philo->second_fork->fork);
}

void	*ft_dinner(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;

	wait_thread(philo->relink_pars); // wait for every thread to start

	// start the actual simulation
	while (!simulation_over(data))
	{
		// Is the philo full ?
		if (philo->is_philo_full)
			break;
		// eat
		eat(philo);
		
		// sleep
		write_status(SLEEP, philo);
		precise_usleep(philo->relink_pars.time2sleep, &philo->relink_pars);

		// 4 think
		think(philo);
	}
	
}

void	turbo_dinner(t_pars **pars)
{
	t_pars *current;

	current = *pars;

	size_t i = 0;
	// ! STEP 1 : if no meals, exit
	if (current->max_meals == 0)
		return ;
	else if (current->nb_philos == 1)// ! STEP 2 : if only one philo, create a specific function for it
		handle_one_philo(pars); // * TOUDOU
	else // ! STEP 3 : CREATE ALL THREADS
	{
		while (i < current->nb_philos)
		{
			pthread_create(current->philos[i].id_thread, NULL, ft_dinner(pars), NULL);
			i++;
		}
	}
	
	// Creating the monitor thread
	pthread_create(current->monitor, NULL, monitor_dinner(), NULL);
	
	// ! STEP 4 : get time of the starting simulation
	current->start_time = get_time(MILLISECOND);
	
	// turn the bool every_thread_ready
	set_bool(&current->mutex_pars, &current->every_thread_ready, true);
	// ! STEP 5 : MAKE THE WHOLE DINNER START AT THE SAME TIME

	// wait for all the thread
	i = 0;
	while (i < current->nb_philos)
	{
		pthread_join(&current->philos[i].id_thread, NULL);
		i++;
	}

	// from here, all the philos are full
	
}
