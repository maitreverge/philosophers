/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:39:27 by flverge           #+#    #+#             */
/*   Updated: 2024/04/03 16:45:27 by flverge          ###   ########.fr       */
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