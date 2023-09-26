/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-i <dlopez-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:13:35 by dlopez-i          #+#    #+#             */
/*   Updated: 2023/09/26 12:53:01 by dlopez-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void    ft_handler(int sig)
{
    static int		bite = 0;
    static unsigned char		ch = '\0';

    ch <<= 1;
    if (sig == SIGUR1))
        ch |= 1;
    bite++;