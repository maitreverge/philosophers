/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/04/03 18:22:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void init_struct(char **av, t_pars *pars)
{
	pars->nb_philos = ft_atoi(av[1]);
	pars->time2die = ft_atoi(av[2]);
	pars->time2eat = ft_atoi(av[3]);
	pars->time2sleep = ft_atoi(av[4]);
	if (av[5])
	{
		pars->max_meals = ft_atoi(av[5]);
		pars->infinite_meals = false;
	}
	else
	{
		pars->max_meals = -1;
		pars->infinite_meals = true;
	}
	// ! init as much philos as necessary
	pars->philos = secure_malloc(sizeof(t_philo) * pars->nb_philos);

	pars->start_simulation = get_time();

	// init mutexes
	ft_mutex(INIT, &pars->write_mutex);

	// init philo struct
	size_t i = 0;
	while (i < pars->nb_philos)
	{
		pars->philos[i].id = i + 1;
		pars->philos[i].is_philo_full = false;
		pars->philos[i].nb_meals = 0;
		pars->philos[i].time_last_meal = pars->start_simulation;
		pars->philos[i].right_fork = NULL;
		ft_mutex(INIT, &pars->philos[i].left_fork);
		if (pars->nb_philos == 1)
			return ;
		// If the current philosopher is the last one in the array
		if (i == pars->nb_philos - 1)
			// Set the right fork of the current philosopher to be the same as its left fork.
			// This is because in a circular table setup, the last philosopher's right fork is the first philosopher's left fork.
			pars->philos[i].right_fork = &pars->philos[0].left_fork;
		else
			// For all other philosophers, their right fork is the left fork of the next philosopher.
			pars->philos[i].right_fork = &pars->philos[i + 1].left_fork;
		i++;
	}
	
}

int main(int ac, char **av)
{
	t_pars pars;
	pthread_mutex_t mutex;

	// pars = 0;
	if (arg_checker(ac, av) == true)
	{
		// ! Need to init philo and fork structs
		init_struct(av, &pars);
		// print_struct(&pars);
		
		// ! start the dinner
		// turbo_dinner(&pars);
		
		// ! clean all the stuff
		// free(pars);
		ft_mutex(DESTROY, &mutex);
	}
	return (0);
}