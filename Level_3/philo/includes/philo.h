/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mbernede <mbernede@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 18:18:57 by mbernede      #+#    #+#                 */
/*   Updated: 2023/07/19 17:43:18 by mbernede      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/time.h>
# include <stdbool.h>

# define ERROR 1
# define SUCCES 0

# define V_TAKE_FORK 1
# define V_EAT 2
# define V_SLEEP 3
# define V_THINK 4
# define V_DIED 5

# define ERR_ARG "Correct Usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat].\n"
# define ERR_INPUT "Error\n"
# define ERR "Error\n"

typedef struct s_philos
{
	int				id;
	long long		t_start;
	int				meals;
	bool			alive;
	long long		t_die;
	pthread_mutex_t	*m_alive;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_args
{
	int			phi_nb;
	long long	t_to_die;
	long long	t_to_eat;
	long long	t_to_sleep;
	int			eat_max;
}	t_args;

typedef struct s_rules
{
	t_args			*arg;
	pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*m_alive;
	pthread_mutex_t	m_stop_loop;
	int				kill_loop;
}	t_rule;

typedef struct s_philo_thread
{
	t_philo	*philo;
	t_args	*arg;
}	t_philo_thread;

//actions.c
void			print_msg(t_philo phi, int msg, int check);
void			start_sleep(t_philo_thread *phi);
void			try_eat(t_philo_thread *phi);

//change.c
void			change_t_died(t_philo_thread *phi);
void			change_end(t_philo *philo);
void			change_all_end(t_rule *rules);

//check.c
int				check_alive(t_philo philo);
int				check_t_alive(t_philo philo);
int				check_all_dead(t_rule *rules);

//error_input.c
int				check_input(char **argv);

//fill.c
int				init_fill(t_rule *rules, char **argv, t_args *arg);
void			fill_philos(t_rule *rules);
void			fill_philo_solo(t_rule *rules, t_philo_thread *phi);
void			fill_to_null(t_rule *rules, t_philo_thread *phi);

//init.c
int				init_all(t_rule *rules, t_philo_thread **phi);

//logic.c
int				start(t_rule *rules);

//main.c
void			wait_all_threads(t_rule *rules);

//philo.c
void			*routine(void *arg);

//time.c
long long		current_time(void);
long long		philo_time_lived(t_philo phi);
int				mini_sleep(int time, t_philo_thread *phi);

//UTILS
int				ft_is_number(char *str);
void			free_rule(t_rule *rules);
void			destroy_all(t_rule *rules, t_philo_thread *phi);
void			destroy(t_rule *rules, t_philo_thread *phi);
int				ft_strlen(const char *s);
int				ft_atoi_overflow(const char *str, int *numb);
long long		ft_atoll(const char *nb);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);

#endif
