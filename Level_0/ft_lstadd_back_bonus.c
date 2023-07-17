/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:21:43 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 16:33:55 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptrlst;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		ptrlst = ft_lstlast(*lst);
		ptrlst->next = new;
	}
	else
		*lst = new;
}
