#include "../includes/philo.h"

void	print_struct(t_philo **data)
{
	t_philo *node;

	node = *data;

	if (!node)
		return ;
	printf("Number of philo = %zu\n", node->nb_philos);
	printf("Time To Die = %zu\n", node->time2die);
	printf("Time To Eat = %zu\n", node->time2eat);
	printf("Time To Sleep = %zu\n", node->time2sleep);
	if (node->nb_meals)
		printf("Nb of minimum meals = %i\n", node->nb_meals);
}