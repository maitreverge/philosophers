/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:39:27 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 11:21:33 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			result;

	if (gettimeofday(&time, NULL) == -1)
		custom_exit("gettimeofday failed\n");
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

void	ft_usleep(long time_input)
{
	long	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_input)
		usleep(time_input / 10);
}
