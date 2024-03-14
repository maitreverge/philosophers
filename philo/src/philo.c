/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/03/14 17:43:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		new_node->max_meals = ft_atoi(av[5]);

	return (new_node);
}

void	custom_exit(char *s)
{
	printf("%s\n");
	exit(EXIT_FAILURE);
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
			custom_exit("Time should be above 60ms");
		// print_struct(&data);
		// ! start the dinner
		// code
		
		// ! clean all the stuff
		free(data);
	}
	return (0);
}