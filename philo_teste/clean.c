/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:47:38 by felipe            #+#    #+#             */
/*   Updated: 2024/06/26 17:43:13 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void clean(t_data *data)
{
    t_philo *philo;
    int i;

    i = -1;
    while (++i < data->number_of_philosophers)
    {
        philo = data->philos + 1; 
        pthread_mutex_destroy(&data->forks[i].fork);
    }
    pthread_mutex_destroy(&data->write_mutex);
    pthread_mutex_destroy(&data->data_mutex);
    pthread_mutex_destroy(&data->philos->philo_mutex);
    free(data->forks);
    free(data->philos);
}

void de_philo(t_philo *philo)
{
    if (philo->data->number_of_philosophers % 2 == 0)
    {
        if (philo->id % 2 == 0)
            usleep(3e4);
    }
    else
    {
        if (philo->id % 2)
            think(philo, true);
    }
}