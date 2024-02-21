/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/02/21 13:01:17 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo *init_struct(int ac, char **av)
{
	t_philo *new_node;

	new_node->nb_philos = ft_atoi(av[1]);
	new_node->time2die = ft_atoi(av[2]);
	new_node->time2eat = ft_atoi(av[3]);
	new_node->time2sleep = ft_atoi(av[4]);
	if (av[5])
		new_node->nb_meals = ft_atoi(av[4]);

	return (new_node);
}

int main(int ac, char **av)
{
	t_philo *data;

	data = NULL;
	if (arg_checker(ac, av) == true)
	{
		data = init_struct(ac, av);
		// printf("Okay\n\n");
		free(data);
	}
	return (0);
}