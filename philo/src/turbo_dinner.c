/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:35 by flverge           #+#    #+#             */
/*   Updated: 2024/04/04 17:26:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*is_dead(void	*data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->pa->time2die + 1);
	pthread_mutex_lock(&ph->pa->time_eat);
	pthread_mutex_lock(&ph->pa->is_full);
	if (!check_death(ph, 0) && !ph->is_full && ((actual_time() - ph->time_last_meal) \
		>= (long)(ph->pa->time2die)))
	{
		pthread_mutex_unlock(&ph->pa->time_eat);
		pthread_mutex_unlock(&ph->pa->is_full);
		pthread_mutex_lock(&ph->pa->write_mutex);
		write_status("died\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		check_death(ph, 1);
	}
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->is_full);
	return (NULL);
}

void	*ft_dinner(void *data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->time2eat / 10);
	while (!check_death(ph, 0))
	{
		pthread_create(&ph->thread_death_id, NULL, is_dead, data);
		activity(ph);
		pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_meals == ph->pa->max_meals)
		{
			pthread_mutex_lock(&ph->pa->is_full);
			ph->is_full = 1;
			ph->pa->nb_p_finish++;
			if (ph->pa->nb_p_finish == ph->pa->nb_philos)
			{
				pthread_mutex_unlock(&ph->pa->is_full);
				check_death(ph, 2);
			}
			pthread_mutex_unlock(&ph->pa->is_full);
			return (NULL);
		}
	}
	return (NULL);
}

int	turbo_dinner(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->a.nb_philos)
	{
		p->ph[i].pa = &p->a;
		if (pthread_create(&p->ph[i].thread_id, NULL, ft_dinner, &p->ph[i]) != 0)
			return (custom_exit("Pthread did not return 0\n"));
		i++;
	}
	return (1);
}