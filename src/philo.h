#ifndef PHILO_H
# define PHILO_H

#include "../libft/libft.h"
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

enum	state
{
	THINKING = 0,
	HUNGRY = 1,
	EATING = 2,
	SLEEPING = 3
};

typedef struct s_status
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int state;
}			t_status;

typedef struct	s_philo
{
	int				pos;
	int				nb_eat;
	pthread_t		thread;
	t_status		status;
	struct s_philo	*next;
	pthread_mutex_t	lfork_m;
	pthread_mutex_t	rfork_m;
}			t_philo;

typedef struct	s_list
{
	t_philo	*first;
}			t_list;

t_list	*init_list();
void	insert_philo(t_list *list, int pos);
void	print_list(t_list *list);

#endif