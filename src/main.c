#include "./philo.h"

// void	*roll_dice()
// {
// 	int	value = (rand() % 6) + 1;
// 	int	*result = malloc(sizeof(int));

// 	*result = value;
// 	return (void *)result;
// }

// int	start_threads(t_philo *philo, int nb_philo)
// {
// 	int	i;
// 	int	*res;

// 	i = -1;
// 	while (++i < nb_philo)
// 	{
// 		if (pthread_create(&philo.thread[i], NULL, &roll_dice, NULL) != 0)
// 			return 1;
// 		printf("Thread %d has started\n", i);
// 	}
// 	i = -1;
// 	while (++i < nb_philo)
// 	{
// 		if (pthread_join(&philo.thread[i], (void **)&res) != 0)
// 			return 2;
// 		printf("Dice %d rolled: %d\n", i + 1, *res);
// 	}
// 	free(res);
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	int	nb_philo;
	t_list *philosophers;
	int	i;

	if (argc >= 5)
	{
		nb_philo = ft_atoi(argv[1]);
		philosophers = init_list();
		i = 1;
		printf("%d\n", nb_philo);
		while (i < nb_philo)
			insert_philo(philosophers, ++i);
		print_list(philosophers);
	}
	return (0);
}