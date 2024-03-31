/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/03/31 18:45:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// 1.16.15

void	get_forks(t_philo *philo, t_fork *forks, int i)
{
	int philo_nbr = philo->relink_pars.nb_philos;

	philo->first_fork = &forks[(i + 1) % philo_nbr];
	philo->second_fork = &forks[i];
	if (philo->id % 2)
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[(i + 1) % philo_nbr];
	}
	
}

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
	
	new_node->every_thread_ready = false; // syncronization of threads

	ft_mutex(INIT, &new_node->mutex_pars);
	ft_mutex(INIT, &new_node->mutex_write);

	new_node->forks = secure_malloc(sizeof(t_fork) * new_node->nb_philos);
	int i = 0;
	//init forks mutexes
	while (i < new_node->nb_philos)
	{
		ft_mutex(INIT, &new_node->forks[i].fork);
		new_node->forks[i].id_fork = i; // init the ids of forks
		i++;
	}
	
	new_node->philos = secure_malloc(sizeof(t_philo) * new_node->nb_philos);
	i = 0;
	// init philo thread
	t_philo *philo;
	while (i < new_node->nb_philos)
	{
		philo = &new_node->philos[i];
		philo->id = i;
		philo->nb_meals = 0;
		philo->is_philo_full = false;
		philo->relink_pars = *new_node;
		ft_mutex(INIT, &philo->philo_mutex);
		
		get_forks(philo, new_node->forks, i);
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
	pthread_mutex_t mutex;


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
		turbo_dinner(&data);
		
		// ! clean all the stuff
		free(data);
		ft_mutex(DESTROY, &mutex);
	}
	return (0);
}