#ifndef PHILO_H
# define PHILO_H

#include "../libft/libft.h"
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_philo
{
	int			pos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_eat;
	pthread_t	thread;
	struct t_philo		*next;
}			t_philo;

#endif