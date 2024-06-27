/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:00:42 by felipe            #+#    #+#             */
/*   Updated: 2024/06/27 12:43:44 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_usleep(long time, t_data *data)
{
	long	start;
	long	elapsed;
	long	rem;

	start = gettime(MICROSECONDS);
	while (gettime(MICROSECONDS) - start < time)
	{
		if (simu_end(data))
			break ;
		elapsed = gettime(MICROSECONDS) - start;
		rem = time - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
			while (gettime(MICROSECONDS) - start < time)
				;
	}
}
