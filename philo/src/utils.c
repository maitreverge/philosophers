/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:34 by flverge           #+#    #+#             */
/*   Updated: 2024/03/14 18:10:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	is_philo_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '+')
		return (true);
	return (false);
}

void	custom_exit(char *s)
{
	printf(RED"⛔ %s ⛔\n"RESET, s);
	exit(EXIT_FAILURE);
}

void	*secure_malloc(size_t size)
{
	void	*result;
	
	result = malloc(size);
	if (!result)
		custom_exit("Malloc failed allocating memory");
	return (result);
}
