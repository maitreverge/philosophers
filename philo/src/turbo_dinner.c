/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:35 by flverge           #+#    #+#             */
/*   Updated: 2024/04/03 18:50:23 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *ft_dinner(void *data)
{
	t_pars *pars;

	pars = (t_pars *)data; // ugly shit

	
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