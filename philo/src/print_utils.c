#include "../includes/philo.h"

void	print_struct(t_pars *data)
{
	// t_pars *data;

	// data = *data;

	if (!data)
		return ;
	printf("Number of philo = %zu\n", data->nb_philos);
	printf("Time To Die = %zu\n", data->time2die);
	printf("Time To Eat = %zu\n", data->time2eat);
	printf("Time To Sleep = %zu\n", data->time2sleep);
	printf("Nb of maximum meals = %i\n", data->max_meals);
}