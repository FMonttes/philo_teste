/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:00:42 by felipe            #+#    #+#             */
/*   Updated: 2024/06/24 22:03:23 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    smart_usleep(long time, t_data *data)
{
    long start;
    long elapsed;
    long rem;

    start = gettime(MICROSECONDS);
    while (gettime(MICROSECONDS) - start < time)
    {
        if (simu_end(data))
            break;
        elapsed = gettime(MICROSECONDS) - start;
        rem = time - elapsed;
        if (rem > 1e3)
            usleep(time / 2);
        else
            while (gettime(MICROSECONDS) - start < time)
                ;
    }
}