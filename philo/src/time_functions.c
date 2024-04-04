/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:39:27 by flverge           #+#    #+#             */
/*   Updated: 2024/04/04 16:47:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long get_time(void)
{
	long result;
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		custom_exit("gettimeofday failed\n");
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return result; 
}

// Function to make the program sleep for a specified amount of time
void	ft_usleep(long time_input)
{
	long start_time;

	start_time = 0;
	start_time = get_time();

	// Loop until the difference between the current time and the start time is less than the input time
	// Make the program sleep for a tenth of the input time
	while ((get_time() - start_time) < time_input)
		usleep(time_input / 10);
}