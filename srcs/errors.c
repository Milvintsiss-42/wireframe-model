/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:02:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/24 21:25:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_perror(char *error_str)
{
	ft_putstr_fd(error_str, 2);
	return (1);
}

int	ft_perror_errno(char *error_str)
{
	perror(error_str);
	return (1);
}
