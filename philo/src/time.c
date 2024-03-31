/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:45:12 by flverge           #+#    #+#             */
/*   Updated: 2024/03/31 16:56:22 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long get_time(t_time_code time_code)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		custom_exit("Get time of the day failed");
	if (time_code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (time_code == MILLISECOND)
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (time_code == MICROSECOND)
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	else
		custom_exit("Wrong input on get_time function");
	return (42);
}

// precise usleep function
void precise_usleep(long usec, t_pars *pars)
{
	long start;
	long ecoule;
	long reste;


	start = get_time(MICROSECOND);

	while (get_time(MICROSECOND - start) < usec)
	{
		if (simulation_over(pars))
			break;
		ecoule = get_time(MICROSECOND) - start;
		reste = usec - ecoule;

		if (reste > 1000)
			usleep(usec / 2);
		else
		{
			while (get_time(MICROSECOND - start) < usec)
				;
		}
	}
}
