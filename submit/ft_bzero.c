/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:10:27 by stuna             #+#    #+#             */
/*   Updated: 2023/11/06 18:39:35 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *destp, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)destp)[i] = 0;
		i++;
	}
}
