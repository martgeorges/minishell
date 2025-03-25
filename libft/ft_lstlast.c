/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:02:15 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/16 16:22:14 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Returns the last node of the list

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst ->next == NULL)
			return (lst);
		lst = lst ->next;
	}
	return (lst);
}
