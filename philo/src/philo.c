/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/04/03 16:38:41 by flverge          ###   ########.fr       */
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