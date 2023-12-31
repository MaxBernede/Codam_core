/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisse <jisse@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:19:36 by jmeruma           #+#    #+#             */
/*   Updated: 2023/06/29 16:31:25 by jisse            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_2dfree(char **p_arr)
{
	int	i;

	i = 0;
	if (!p_arr)
		return ;
	while (p_arr[i] != NULL)
	{
		free(p_arr[i]);
		i++;
	}
	free(p_arr);
}
