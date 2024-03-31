/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:57:37 by flverge           #+#    #+#             */
/*   Updated: 2024/03/31 17:24:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_status(t_philo_status code, t_philo *philo)
{
	long ecoule;

	if (philo->is_philo_full)
		return;

	ecoule = get_time(MILLISECOND) - philo->relink_pars.start_time;
	ft_mutex(LOCK, &philo->relink_pars.mutex_write);

	if (code == EAT && !simulation_over(&philo->relink_pars))
		printf("[%ld] [philo_%d] is eating", ecoule, philo->id + 1);
	else if (code == SLEEP && !simulation_over(&philo->relink_pars))
		printf("[%ld] [philo_%d] is sleeping", ecoule, philo->id + 1);
	else if (code == THINK && !simulation_over(&philo->relink_pars))
		printf("[%ld] [philo_%d] is thinking", ecoule, philo->id + 1);
	else if (code == DIE && !simulation_over(&philo->relink_pars))
		printf("[%ld] [philo_%d] died", ecoule, philo->id + 1);
	else if ((code == TAKE_FORK_1 || code == TAKE_FORK_2) && !simulation_over(&philo->relink_pars))
		printf("[%ld] [philo_%d] has taken a fork ", ecoule, philo->id + 1);
	
	ft_mutex(UNLOCK, &philo->relink_pars.mutex_write);
}