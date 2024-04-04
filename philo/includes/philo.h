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

typedef struct s_arg
{
	int						nb_philos;
	int						time2die;
	int						time2eat;
	int						time2sleep;
	int						max_meals;
	long int				start_simulation;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			is_full;
	int						nb_p_finish;
	int						stop;
}							t_arg;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			left_fork;
	t_arg					*pa;
	long int				time_last_meal;
	unsigned int			nb_meals;
	int						is_full;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}							t_p;

/*
** functions
*/

int				parse_args(int argc, char **argv, t_p *p);
int				initialize(t_p *p);
int				custom_exit(char *str);
void			write_status(char *str, t_philo *ph);
long int		actual_time(void);
void			ft_putstright_forkd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
int				threading(t_p *p);
void			activity(t_philo *ph);
int				check_death(t_philo *ph, int i);
int				ft_strlen(char *str);

bool nb_args_ok(int ac);
void	print_usage(void);
bool arg_checker(int ac, char **av);

void	*secure_malloc(size_t size);





#endif