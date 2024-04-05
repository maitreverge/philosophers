/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:52:29 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 12:47:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sleep_think(t_philo *ph)
{
	ft_mutex(LOCK, &ph->pa->write_mutex);
	write_status("is sleeping\n", ph);
	ft_mutex(UNLOCK, &ph->pa->write_mutex);
	ft_usleep(ph->pa->time2sleep);
	ft_mutex(LOCK, &ph->pa->write_mutex);
	write_status("is thinking\n", ph);
	ft_mutex(UNLOCK, &ph->pa->write_mutex);
}

static void	lock_forks(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		ft_mutex(LOCK, &ph->left_fork);
		ft_mutex(LOCK, ph->right_fork);
	}
	else
	{
		ft_mutex(LOCK, ph->right_fork);
		ft_mutex(LOCK, &ph->left_fork);
	}
}

static void	unlock_forks(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		ft_mutex(UNLOCK, ph->right_fork);
		ft_mutex(UNLOCK, &ph->left_fork);
	}
	else
	{
		ft_mutex(UNLOCK, &ph->left_fork);
		ft_mutex(UNLOCK, ph->right_fork);
	}
}

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

void	activity(t_philo *ph)
{
	lock_forks(ph);
	ft_mutex(LOCK, &ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	write_status("has taken a fork\n", ph);
	ft_mutex(UNLOCK, &ph->pa->write_mutex);
	if (!ph->right_fork)
	{
		ft_usleep(ph->pa->time2die * 2);
		return ;
	}
	ft_mutex(LOCK, &ph->pa->write_mutex);
	write_status("is eating\n", ph);
	ft_mutex(LOCK, &ph->pa->time_eat);
	ph->time_last_meal = get_time();
	ft_mutex(UNLOCK, &ph->pa->time_eat);
	ft_mutex(UNLOCK, &ph->pa->write_mutex);
	ft_usleep(ph->pa->time2eat);
	unlock_forks(ph);
	sleep_think(ph);
}
