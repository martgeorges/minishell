/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:36:12 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/18 09:37:21 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Takes as a parameter a node and frees the memory of
//the node’s content using the function ’del’ given
//as a parameter and free the node. The memory of
//’next’ must not be freed.

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst ->content);
		free(lst);
	}
}
