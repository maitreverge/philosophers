 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:18 by flverge           #+#    #+#             */
/*   Updated: 2024/02/21 13:12:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <string.h>   // memset
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <unistd.h>   // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h>
//         ||
//         V 
// pthread_create, pthread_detach, pthread_join, pthread_mutex_init
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

typedef struct s_pars
{
	size_t nb_philos;
	size_t time2die;
	size_t time2eat;
	size_t time2sleep;
	int max_meals; // ? nb of meals can be negative ??
}		t_pars;

typedef	struct s_fork
{
	pthread_mutex_t fork;
	size_t id_fork;
}		t_fork;

typedef struct s_philo
{
	size_t id_philo;
	t_fork *right_fork;
	t_fork *left_fork;
	size_t nb_meals;
	bool is_philo_full;
}		t_philo;


bool	is_philo_digit(int c);

// init_check
void	print_usage(void);
bool arg_checker(int ac, char **av);

int	ft_atoi(const char *str);

void	print_struct(t_pars **data);

int	ft_isdigit(int c);










#endif