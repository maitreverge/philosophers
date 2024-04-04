/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:35 by flverge           #+#    #+#             */
/*   Updated: 2024/04/04 16:54:09 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool is_philo_dead()
{
	
}

void *ft_dinner(void *data)
{
	t_pars *pars;

	pars = (t_pars *)data; // ugly shit

	if (pars->philos->id % 2 == 0)
	{
		ft_usleep(pars->time2eat / 10);
	}
	while (!is_philo_dead(pars, 0)) // ! TO DO
	{
		
	}
	
	
}

void	turbo_dinner(t_pars *pars)
{
	size_t i;

	i = 0;
	while (i < pars->nb_philos)
	{
		pthread_create(&pars->philos[i].id_thread, NULL, ft_dinner, pars);
		i++;
	}
}