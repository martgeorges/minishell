/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:51:12 by laichoun          #+#    #+#             */
/*   Updated: 2024/03/15 13:35:44 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Allocates (with malloc(3)) and returns a new node.
//The member variable ’content’ is initialized with
//the value of the parameter ’content’. The variable
//’next’ is initialized to NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element ->content = content;
	element ->next = NULL;
	return (element);
}
