#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	*roll_dice()
{
	int	value = (rand() % 6) + 1;
	int	*result = malloc(sizeof(int));

	*result = value;
	return (void *)result;
}

int	main(int argc, char *argv[])
{
	int	nb_philo;
	pthread_t t[nb_philo];
	int	i;
	int	*res;

	nb_philo = ft_atoi(argv[1]);
	i = -1;
	while (++i < 5)
	{
		if (pthread_create(&t[i], NULL, &roll_dice, NULL) != 0)
			return 1;
		printf("Thread %d has started\n", i);
	}
	i = -1;
	while (++i < 5)
	{
		if (pthread_join(t[i], (void **)&res) != 0)
			return 2;
		printf("Dice %d rolled: %d\n", i + 1, *res);
	}
	free(res);
	return (0);
}