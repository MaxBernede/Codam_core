/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:26:14 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/15 18:56:11 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptrlist;

	ptrlist = (t_list *)malloc(sizeof(*ptrlist));
	if (!ptrlist)
		return (NULL);
	ptrlist->content = content;
	ptrlist->next = NULL;
	return (ptrlist);
}
