/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:58:15 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/16 13:55:59 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds the node ’new’ at the beginning of the list.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
			new ->next = *lst;
		*lst = new;
	}
	else
		new ->next = NULL;
}
