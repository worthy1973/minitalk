/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:02:02 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/09/19 15:08:06 by dlopez-i         ###   ########.fr       */
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
        if (usleep(200) == ERROR)
            exit (error_msg(E_US, EXIT_FAILURE));
    }   
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
			i++;
	}
	return (r * s);
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
