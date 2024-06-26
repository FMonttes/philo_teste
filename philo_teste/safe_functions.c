/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:01:50 by felipe            #+#    #+#             */
/*   Updated: 2024/06/25 18:16:04 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *safe_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (!ptr)
    {
        printf(RED"Error: Malloc failed\n"RST);
        return (NULL);
    }
    return (ptr);
}

static void handle_error_mutex(int status, t_opcode opcode)
{
    if ( status == 0)
        return;
    if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
        print_error("Invalid mutex");        
    else if (EINVAL == status && opcode == INIT)
        print_error("Invalid mutex attributes");        
    else if (status == EDEADLK)
        print_error(RED"Error: Mutex is already locked\n"RST);
    else if (status == ENOMEM)
        print_error(RED"Error: Insufficient memory\n"RST);
    else if (status == EBUSY)
        print_error(RED"Error: Mutex is already locked\n"RST);
    else if (status == EPERM)
        print_error(RED"Error: Mutex is already locked\n"RST);
    else
        print_error(RED"Error: Unknown error\n"RST);
}

void safe_mutex(pthread_mutex_t *mutex, t_opcode opcode)
{
    if (opcode == LOCK)
        /* handle_error_mutex( */pthread_mutex_lock(mutex);/* , opcode); */
    else if (opcode == UNLOCK)
        /* handle_error_mutex( */pthread_mutex_unlock(mutex);/* , opcode); */
    else if (opcode == DESTROY)
        /* handle_error_mutex( */pthread_mutex_destroy(mutex);/* , opcode); */
    else if (opcode == INIT)
        /* handle_error_mutex( */pthread_mutex_init(mutex, NULL);
    {
        /* printf(RED"Error: Invalid opcode\n"RST); */
        return ;
    }
}

void handle_thread_error(int status, t_opcode opcode)
{
    if (status == 0)
        return ;
    if (status == EINVAL && opcode == JOIN)
        print_error("Invalid thread");
    else if (status == EINVAL && opcode == CREATE)
        print_error("Invalid thread attributes");
    else if (status == ESRCH)
        print_error("No thread found");
    else if (status == EAGAIN)
        print_error("Insufficient resources to create another thread");
    else if (status == EDEADLK)
        print_error("Deadlock detected");
    else if (status == EPERM)
        print_error("No permission to set the scheduling policy and parameters specified in attr");
    else if (status == EPERM)
        print_error("No permission to set the scheduling policy and parameters specified in attr");
    else
        print_error("Unknown error");
}

void safe_thread(pthread_t *thread, 
    t_opcode opcode, void *(*func)(void *), void *data)
{
    if (opcode == JOIN)
        /* handle_thread_error */pthread_join(*thread, NULL);/* , opcode); */
    else if (opcode == CREATE)
        /* handle_thread_error */pthread_create(thread, NULL, func, data);/* , opcode); */
    else
    {
        /* printf(RED"Error: Invalid opcode\n"RST); */
        return ;
    }
}