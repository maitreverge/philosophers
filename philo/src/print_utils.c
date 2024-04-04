#include "../includes/philo.h"

void	print_struct(t_arg *data)
{
	// t_pars *data;

	// data = *data;

	if (!data)
		return ;
	printf("Number of philo = %i\n", data->nb_philos);
	printf("Time To Die = %i\n", data->time2die);
	printf("Time To Eat = %i\n", data->time2eat);
	printf("Time To Sleep = %i\n", data->time2sleep);
	printf("Nb of maximum meals = %i\n", data->max_meals);
}