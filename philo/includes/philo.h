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

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define RESET   "\033[0m"

enum e_mutex_code
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
};

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}		t_time_code;


typedef	struct s_fork
{
	pthread_mutex_t fork;
	size_t id_fork;
}		t_fork;

typedef struct s_philo
{
	size_t id;
	size_t nb_meals;
	bool is_philo_full;
	t_fork *first_fork;
	t_fork *second_fork;
	t_pars relink_pars;
	pthread_t id_thread;
}		t_philo;

typedef struct s_pars
{
	size_t nb_philos;
	size_t time2die;
	size_t time2eat;
	size_t time2sleep;
	bool 	infinite_meals;
	size_t max_meals; // ? nb of meals can be negative ??
	unsigned long start_time;
	t_fork *forks;
	t_philo *philos;
	bool every_thread_ready;
	pthread_mutex_t mutex_pars;
	bool is_diner_over;
}		t_pars;

bool	is_philo_digit(int c);

// init_check
void	print_usage(void);
bool arg_checker(int ac, char **av);

size_t	ft_atoi(const char *str);

void	print_struct(t_pars **data);

bool	ft_isdigit(int c);

void	custom_exit(char *s);

void	*secure_malloc(size_t size);

void	ft_mutex(int code, pthread_mutex_t *mutex);

void set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool get_bool(pthread_mutex_t *mutex, bool *value);
void set_sizet(pthread_mutex_t *mutex, size_t *dest, size_t value);
size_t get_sizet(pthread_mutex_t *mutex, size_t *value);


bool simulation_over(t_pars *pars);

void	wait_thread(t_pars *pars);

long get_time(t_time_code time_code);







#endif