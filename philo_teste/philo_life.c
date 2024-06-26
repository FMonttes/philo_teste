/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:34:23 by felipe            #+#    #+#             */
/*   Updated: 2024/06/26 07:20:01 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_philo *philo)
{
    safe_mutex(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo);
    safe_mutex(&philo->sec_fork->fork, LOCK);
    write_status(TAKE_SEC_FORK, philo);
    set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECONDS));
    philo->meals_counter++;
    write_status(EATING, philo);
    smart_usleep(philo->data->time_to_eat, philo->data);
    if (philo->data->number_of_eat > 0 && 
    philo->meals_counter == philo->data->number_of_eat)
        set_bool(&philo->philo_mutex, &philo->full, true);
    safe_mutex(&philo->first_fork->fork, UNLOCK);
    safe_mutex(&philo->sec_fork->fork, UNLOCK); 
}

static void think(t_philo *philo)
{
    write_status(THINKING, philo);
}

void wait_threads(t_data *data)
{
    while (!get_bool(&data->data_mutex, &data->all_threads_ready))
        usleep(50);
}

void    *philo_life(void *data)
{
   t_philo  *philo;

   philo = (t_philo *)data;
   wait_threads(philo->data);
   set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECONDS));
   increase_long(&philo->data->data_mutex, 
   &philo->data->threads_running_nbr);
   while (!simu_end(philo->data))
   {
        if (philo->full)
            break;
        eat(philo);
        write_status(SLEEPING, philo);
        smart_usleep(philo->data->time_to_sleep, philo->data);
        think(philo);
   }
}