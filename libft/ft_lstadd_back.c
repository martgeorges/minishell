/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:01:32 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/16 16:32:51 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds the node ’new’ at the end of the list.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			last = ft_lstlast(*lst);
			last ->next = new;
		}
		else
			*lst = new;
	}
	else
		new ->next = NULL;
}
