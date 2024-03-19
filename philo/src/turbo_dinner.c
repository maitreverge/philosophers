/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:35 by flverge           #+#    #+#             */
/*   Updated: 2024/03/19 17:47:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_one_philo(t_pars **pars)
{
	// code
}

void	*ft_dinner(t_pars **pars)
{
	
}

void	turbo_dinner(t_pars **pars)
{
	t_pars *current;

	current = *pars;

	// ! STEP 1 : if no meals, exit
	if (current->max_meals == 0)
		return ;
	else if (current->nb_philos == 1)// ! STEP 2 : if only one philo, create a specific function for it
		handle_one_philo(pars); // * TOUDOU
	else
	{
		int i = 0;
		while (i < current->nb_philos)
		{
			pthread_create(current->philos[i].id_thread, NULL, ft_dinner(pars), NULL);
			i++;
		}
	}
	
	// ! STEP 3 : CREATE ALL THREADS
	// ! STEP 4 : CREATE A DEAD PHILO CHECHER
	// ! STEP 5 : MAKE THE WHOLE DINNER START AT THE SAME TIME
}