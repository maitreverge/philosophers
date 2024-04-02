/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/04/02 19:05:22 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 1.16.15

void init_struct(int ac, char **av, t_pars *pars)
{
	pars->nb_philos = ft_atoi(av[1]);
	pars->time2die = ft_atoi(av[2]);
	pars->time2eat = ft_atoi(av[3]);
	pars->time2sleep = ft_atoi(av[4]);
	if (ac == 6 && av[5])
	{
		pars->max_meals = ft_atoi(av[5]);
		pars->infinite_meals = false;
	}
	else
	{
		pars->max_meals = -1;
		pars->infinite_meals = true;
	}
}

int main(int ac, char **av)
{
	t_pars pars;
	pthread_mutex_t mutex;

	pars = NULL;
	if (arg_checker(ac, av) == true)
	{
		// ! Need to init philo and fork structs
		init_struct(ac, av, &pars);
		if (data_wrong_time(&pars))
		{
			free(data);
			custom_exit("Time should be above 60ms");
		}
		// print_struct(&data);
		// ! start the dinner
		turbo_dinner(&data);
		
		// ! clean all the stuff
		free(data);
		ft_mutex(DESTROY, &mutex);
	}
	return (0);
}