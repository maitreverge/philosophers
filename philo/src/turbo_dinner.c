/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turbo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:26:35 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 11:49:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_philo_dead(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->pa->dead);
	if (i)
		ph->pa->stop = i;
	if (ph->pa->stop)
	{
		pthread_mutex_unlock(&ph->pa->dead);
		return (1);
	}
	pthread_mutex_unlock(&ph->pa->dead);
	return (0);
}

static void	*is_dead(void	*data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->pa->time2die + 1);
	pthread_mutex_lock(&ph->pa->time_eat);
	pthread_mutex_lock(&ph->pa->is_full);
	if (!is_philo_dead(ph, 0) && !ph->is_full
		&& ((get_time() - ph->time_last_meal) \
		>= (long)(ph->pa->time2die)))
	{
		pthread_mutex_unlock(&ph->pa->time_eat);
		pthread_mutex_unlock(&ph->pa->is_full);
		pthread_mutex_lock(&ph->pa->write_mutex);
		write_status("died\n", ph);
		pthread_mutex_unlock(&ph->pa->write_mutex);
		is_philo_dead(ph, 1);
	}
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->is_full);
	return (NULL);
}

static void	*ft_dinner(void *data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->pa->time2eat / 10);
	while (!is_philo_dead(ph, 0))
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
				is_philo_dead(ph, 2);
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
		if (pthread_create(&p->ph[i].thread_id, 0, ft_dinner, &p->ph[i]) != 0)
		{
			custom_exit("Pthread did not return 0\n");
			return (0);
		}
		i++;
	}
	return (1);
}
