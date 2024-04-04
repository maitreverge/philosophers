/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:52:29 by flverge           #+#    #+#             */
/*   Updated: 2024/04/04 18:38:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_status(char *str, t_philo *ph)
{
	long int		time;

	time = -1;
	time = get_time() - ph->pa->start_simulation;
	if (time >= 0 && time <= 2147483647 && !is_philo_dead(ph, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", ph->id, str);
	}
}

void	sleep_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->time2sleep);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
}

void	activity(t_philo *ph)
{
	pthread_mutex_lock(&ph->left_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	if (!ph->right_fork)
	{
		ft_usleep(ph->pa->time2die * 2);
		return ;
	}
	pthread_mutex_lock(ph->right_fork);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is eating\n", ph);
	pthread_mutex_lock(&ph->pa->time_eat);
	ph->time_last_meal = get_time();
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->time2eat);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(&ph->left_fork);
	sleep_think(ph);
}