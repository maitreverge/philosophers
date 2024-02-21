void	print_struc(t_philo **data)
{
	t_philo *node;

	node = *data;

	if (!node)
		return ;
	printf("Number of philo = %i\n", node->nb_philo);
	printf("Time To Die = %i\n", node->time2die);
	printf("Time To Die = %i\n", node->time2eat);
	printf("Time To Die = %i\n", node->time2spleep);
	printf("Time To Die = %i\n", node->nb_philo)
}