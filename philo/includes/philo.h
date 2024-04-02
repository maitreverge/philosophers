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

typedef pthread_mutex_t mutex;

typedef struct s_philo t_philo;

typedef enum e_mutex_code
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
} t_mutex_code;

typedef enum e_philo_status
{
	EAT,
	SLEEP,
	THINK,
	DIE,
	TAKE_FORK_1,
	TAKE_FORK_2,
}		t_philo_status;


typedef struct s_philo
{
	size_t id;
	size_t nb_meals;
	bool is_philo_full;
	pthread_t id_thread;
	mutex *first_fork;
	mutex *second_fork;

}		t_philo;

typedef struct s_pars
{
	size_t nb_philos;
	size_t time2die;
	size_t time2eat;
	size_t time2sleep;
	bool 	infinite_meals;
	int max_meals;
	// size_t meal_counter;
}		t_pars;


static bool nb_args_ok(int ac);
static void	error_digit(void);
void	print_usage(void);
bool arg_checker(int ac, char **av);


static bool	ft_isspace(int c);
size_t	ft_atoi(const char *str);
bool	ft_isdigit(int c);

void	print_struct(t_pars **data);

bool	is_philo_digit(int c);
void	custom_exit(char *s);
void	*secure_malloc(size_t size);



#endif