/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:18:38 by flverge           #+#    #+#             */
/*   Updated: 2024/04/05 12:49:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_death(t_p *p)
{
	ft_mutex(LOCK, &p->a.dead);
	if (p->a.stop)
	{
		ft_mutex(UNLOCK, &p->a.dead);
		return (1);
	}
	ft_mutex(UNLOCK, &p->a.dead);
	return (0);
}

static void	stop(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death(p))
		ft_usleep(1);
	while (++i < p->a.nb_philos)
		pthread_join(p->ph[i].thread_id, NULL);
	ft_mutex(DESTROY, &p->a.write_mutex);
	i = -1;
	while (++i < p->a.nb_philos)
		ft_mutex(DESTROY, &p->ph[i].left_fork);
	if (p->a.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->a.max_meals);
	free(p->ph);
}

static int	initialize(t_p *p)
{
	int	i;

	i = 0;
	p->a.start_simulation = get_time();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	init_mutex(p);
	while (i < p->a.nb_philos)
	{
		p->ph[i].id = i + 1;
		p->ph[i].time_last_meal = p->a.start_simulation;
		p->ph[i].nb_meals = 0;
		p->ph[i].is_full = 0;
		p->ph[i].right_fork = NULL;
		ft_mutex(INIT, &p->ph[i].left_fork);
		if (p->a.nb_philos == 1)
			return (1);
		if (i == p->a.nb_philos - 1)
			p->ph[i].right_fork = &p->ph[0].left_fork;
		else
			p->ph[i].right_fork = &p->ph[i + 1].left_fork;
		i++;
	}
	return (1);
}

static bool	init_struct(int ac, char **av, t_p *p)
{
	p->a.nb_philos = ft_atoi(av[1]);
	p->a.time2die = ft_atoi(av[2]);
	p->a.time2eat = ft_atoi(av[3]);
	p->a.time2sleep = ft_atoi(av[4]);
	p->a.max_meals = -1;
	if (ac == 6)
		p->a.max_meals = ft_atoi(av[5]);
	if (p->a.nb_philos <= 0 || p->a.time2die <= 0 || p->a.time2eat <= 0
		|| p->a.time2sleep <= 0 || p->a.max_meals == 0)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_p	p;

	if (arg_checker(ac, av) == true && init_struct(ac, av, &p))
	{
		p.ph = secure_malloc(sizeof(t_philo) * p.a.nb_philos);
		if (p.a.nb_philos == 1)
		{
			alone_philo(&p);
			free(p.ph);
			return (0);
		}
		else if (!initialize(&p) || !turbo_dinner(&p))
		{
			free(p.ph);
			return (0);
		}
		stop(&p);
	}
	return (0);
}
