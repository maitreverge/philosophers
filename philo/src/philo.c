/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/03/13 18:08:01 by flverge          ###   ########.fr       */
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
	new_node->time2die = ft_atoi(av[2]);
	new_node->time2eat = ft_atoi(av[3]);
	new_node->time2sleep = ft_atoi(av[4]);
	if (ac == 6 && av[5])
		new_node->nb_meals = ft_atoi(av[5]);

	return (new_node);
}

int main(int ac, char **av)
{
	t_pars *data;

	data = NULL;
	if (arg_checker(ac, av) == true)
	{
		data = init_struct(ac, av);
		print_struct(&data);
		free(data);
	}
	return (0);
}