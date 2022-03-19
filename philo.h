#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	int		pos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat;
	s_philo	*next;
}			t_philo;

#endif