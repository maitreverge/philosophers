/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/03/15 17:08:23 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 38.02

t_pars *init_struct(int ac, char **av)
{
	t_pars *new_node;

	new_node = malloc(sizeof(t_pars));
	if (!new_node)
		return NULL;
	new_node->nb_philos = ft_atoi(av[1]);
	new_node->time2die = ft_atoi(av[2]) * 1000; // conversion to microseconds
	new_node->time2eat = ft_atoi(av[3]) * 1000;
	new_node->time2sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6 && av[5])
	{
		new_node->max_meals = ft_atoi(av[5]);
		new_node->infinite_meals = false;
	}
	else
	{
		new_node->max_meals = -1;
		new_node->infinite_meals = true;
	}
	
	new_node->is_diner_over = false;

	// ! need to malloc t_philo
	new_node->philos = secure_malloc(sizeof(t_philo) * new_node->nb_philos);
	int i = 0;
	//init forks mutexes
	while (i <= new_node->nb_philos)
	{
		mutex(INIT, &new_node->forks[i].fork);
		i++;
	}
	new_node->forks = secure_malloc(sizeof(t_fork) * new_node->nb_philos);
	i = 0;
	// init philo thread
	t_philo *philo;
	while (i <= new_node->nb_philos)
	{
		philo = &new_node->philos[i];
		philo->id = i;
		philo->is_philo_full = false;
		philo->nb_meals = 0;
		philo->is_philo_full = false;
	}

	return (new_node);
}

bool data_wrong_time(t_pars **pars)
{
	// ! check if ms == micro seconds, read usleep doc
	
	if ((*pars)->time2die < 60000 || (*pars)->time2eat < 60000 || (*pars)->time2sleep < 60000)
		return true;
	return false;
}

int main(int ac, char **av)
{
	t_pars *data;

	data = NULL;
	if (arg_checker(ac, av) == true)
	{
		// ! Need to init philo and fork structs
		data = init_struct(ac, av);
		if (data_wrong_time(&data))
		{
			free(data);
			custom_exit("Time should be above 60ms");
		}
		// print_struct(&data);
		// ! start the dinner
		// code
		
		// ! clean all the stuff
		free(data);
		mutex(DESTROY, &mutex);
	}
	return (0);
}