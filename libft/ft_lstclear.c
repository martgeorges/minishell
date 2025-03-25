/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:38:54 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/18 10:27:59 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Deletes and frees the given node and every
//successor of that node, using the function ’del’
//and free(3).
//Finally, the pointer to the list must be set to NULL.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*position;
	t_list	*tmp;

	position = *lst;
	while (position != NULL)
	{
		tmp = position ->next;
		ft_lstdelone(position, del);
		position = tmp;
	}
	*lst = NULL;
}
