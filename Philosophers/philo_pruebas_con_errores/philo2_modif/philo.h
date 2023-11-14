/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <iarbaiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:47:48 by iarbaiza          #+#    #+#             */
/*   Updated: 2023/11/11 20:16:03 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TAKE_FORK	"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define THINKING	"is thinking"
# define DEAD		"died"

typedef struct s_philo
{
	int				id;
	int				meal;
	long int		last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_list	*lst;
}	t_philo;

typedef struct s_list
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_meals;
	int				dead;
	long int		t_start;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_meal;
	pthread_mutex_t	m_death;
	pthread_mutex_t	m_printf;
	t_philo			*p;
}	t_list;

/* Check_args */
int			check_digit(int argc, char **argv);
int			check_args(int argc, char **argv);
int			check(int argc, char **argv);

/* get_args */
int			get_args(t_list *lst, int argc, char **argv);
void		get_meals(t_list *lst, int num);

/* Initialize */
int			init_forks(t_list *lst, int num);
int			init_mutex(t_list *lst);
int			init_philo(t_list *lst);
int			init_threads(t_list *lst);
int			join_threads(t_list *lst);

/* Actions */
void		one_philo(t_philo *p);
void		eating(t_philo *p);
void		sleeping_thinking(t_philo *p);
int			finish_eating(t_list *lst);

/* Routine */
void		init_meals(t_philo *p);
void		meals(t_philo *p);
long int	print_info(t_philo *p, char *str);
void		*routine(void *args);

/* Check_live */
int			check_if_alive(t_philo *p);
void		philo_dead(t_list *lst, long int time, int i);
void		check_dead(t_list *lst);
void		check_dead_meals(t_list *lst);
long int	get_last_meal(t_list *lst, long int time, int i);

/* Utils */
long int	ft_atoi(char *str);
int			ft_isdigit(int c);
int			ft_strlen(char	*str);
long int	get_time(void);

/* Free */
void		free_everything(t_list *lst);

#endif