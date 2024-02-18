/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:52:47 by flverge           #+#    #+#             */
/*   Updated: 2024/02/18 18:10:15 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool nb_args_ok(int ac)
{
	if (ac < 5)
	{
		printf("\033[0;31m"); // Set the text color to red
		printf("⛔ Error : Missing at least %i arguments ⛔\n\n", 5 - ac);
		printf("\033[0m"); // Resets the text color to default
		print_usage();
		return (false);
	}
	else if (ac > 6)
	{
		printf("\033[0;31m"); // Set the text color to red
		printf("⛔ Error : Too many arguments ⛔\n\n");
		printf("\033[0m"); // Resets the text color to default
		print_usage();
		return (false);
	}
	return (true);
}

static void	error_digit(void)
{
	printf("\033[0;31m"); // Set the text color to red
	printf("⛔ Error : Incorrect(s) argument(s) detected ⛔\n\n");
	printf("\033[0m"); // Resets the text color to default
	print_usage();
}

void	print_usage(void)
{
	printf("Usage :\n./philo ");
	printf("\033[0;32m"); // Set the text color to green
	printf(" <nb_of_philosophers>  <time_to_die>  ");
	printf("<time_to_eat>  <time_to_spleep>  ");
	printf("\033[0m"); // Resets the text color to default
	printf("[ ⚠️  Next Argument Optional ⚠️  ]");
	printf("\033[38;5;214m"); // Set the text color to a shade of orange
	printf("  <nb_of_time_each_philo_must_eat>\n\n");
	printf("\033[0m"); // Resets the text color to default
}

bool arg_checker(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	if (nb_args_ok(ac))
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (!is_philo_digit(av[i][j]))
				{
					error_digit();	
					return (false);
				}
				j++;
			}
			i++;
		}
	}
	else
		return (false);
	return (true);
}
