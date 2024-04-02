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


typedef	struct s_fork
{
	pthread_mutex_t fork;
	size_t id_fork;
}		t_fork;


typedef struct s_pars
{
	size_t nb_philos;
	size_t time2die;
	size_t time2eat;
	size_t time2sleep;
	bool 	infinite_meals;
	size_t max_meals; // ? nb of meals can be negative ??
	// size_t meal_counter;
	unsigned long start_time;
	t_fork *forks;
	t_philo *philos;
	bool every_thread_ready;
	pthread_mutex_t mutex_pars;
	pthread_mutex_t mutex_write;
	bool is_diner_over;
	pthread_t monitor;
	size_t threads_running_nb;
}		t_pars;

typedef struct s_philo
{
	size_t id;
	size_t nb_meals;
	size_t last_meal_time; // ! need init
	bool is_philo_full;
	t_fork *first_fork;
	t_fork *second_fork;
	t_pars relink_pars;
	pthread_t id_thread;
	pthread_mutex_t philo_mutex;

}		t_philo;









#endif