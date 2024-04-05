/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:52:47 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 11:20:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	nb_args_ok(int ac)
{
	if (ac < 5)
	{
		printf(RED);
		printf("⛔ Error : Missing at least %i arguments ⛔\n\n", 5 - ac);
		printf(RESET);
		print_usage();
		return (false);
	}
	else if (ac > 6)
	{
		printf(RED);
		printf("⛔ Error : Too many arguments ⛔\n\n");
		printf(RESET);
		print_usage();
		return (false);
	}
	return (true);
}

static void	error_digit(void)
{
	printf(RED);
	printf("⛔ Error : Incorrect(s) argument(s) detected ⛔\n\n");
	printf(RESET);
	print_usage();
}

void	print_usage(void)
{
	printf("Usage :\n./philo ");
	printf(GREEN);
	printf(" <nb_of_philosophers>  <time_to_die>  ");
	printf("<time_to_eat>  <time_to_spleep>  ");
	printf(RESET);
	printf("[ ⚠️  Next Argument Optional ⚠️  ]");
	printf(YELLOW);
	printf("  <nb_of_meals>\n\n");
	printf(RESET);
}

bool	arg_checker(int ac, char **av)
{
	int	i;
	int	j;

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
