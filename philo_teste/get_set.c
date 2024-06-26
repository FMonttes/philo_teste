/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:42:39 by felipe            #+#    #+#             */
/*   Updated: 2024/06/24 21:44:55 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
    safe_mutex(mutex, LOCK);
    *dest = value;
    safe_mutex(mutex, UNLOCK);
}

bool get_bool(pthread_mutex_t *mutex, bool *src)
{
    bool value;

    safe_mutex(mutex, LOCK);
    value = *src;
    safe_mutex(mutex, UNLOCK);
    return (value);
}

long get_long(pthread_mutex_t *mutex, long *src)
{
    long value;

    safe_mutex(mutex, LOCK);
    value = *src;
    safe_mutex(mutex, UNLOCK);
    return (value);
}

void set_long(pthread_mutex_t *mutex, long *dest, long value)
{
    safe_mutex(mutex, LOCK);
    *dest = value;
    safe_mutex(mutex, UNLOCK);
}

bool simu_end(t_data *data)
{
  return (get_bool(&data->data_mutex, &data->end_simu));
}