/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:58:37 by flverge           #+#    #+#             */
/*   Updated: 2024/04/03 15:58:41 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return true;
	return false;
}

size_t	ft_atoi(const char *str)
{
	int	i;
	size_t	result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	while (ft_isdigit(str[i]))
	{
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	return (result);
}

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}