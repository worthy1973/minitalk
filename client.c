/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:02:02 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/09/19 14:52:37 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int     error_msg(int e, int exit_)
{
    e == E_FA && write("Client: Too few Arguments");
    e == E_MA && write("Client: Too many Arguments");
    e == E_KL && write("Client: No connection with server");
    return (exit_);
}

void    send_signal(int pid, int sig)
{
    if (kill(pid, sig) == ERROR)
        exit (error_msg(E_KL, EXIT_FAILURE));
    if (usleep(100) == ERROR)
        exit (error_msg(E_US, EXIT_FAILURE));
}

void   turn_bin(const int pid)
{
    while (bite >= 0)
    {
        if (((ch >> bite) & 1) == 1)
            send_signal(pid, SIGUSR1);
        else
            send_signal(pid, SIGUSR2);
        bite--;
        if (usleep(200)) == ERROR)
            exit (error_msg(E_US, EXIT_FAILURE));
    }   
}

int main(int ac, char **av)
{
    pid_t  pid;
    int     i;

    i = -1;
    if (ac <= 2)
        exit (error_msg(E_FA, ERROR));
    if (ac >= 4)
        exit (error_msg(E_MA, ERROR));
    pid = ft_atoi(av[1]);
    while (av[2][++i])
    {
        turn_bin(pid, av[2][i], 7);
    turn_bin(pid, '\0',7);
    return (SUCCESS));
    }
}