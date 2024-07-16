/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 06:30:29 by maxliew           #+#    #+#             */
/*   Updated: 2024/07/16 14:10:40 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstindex(t_list **lst, int to_index)
{
	t_list	*head;
	int		index;

	head = *lst;
	index = 0;
	while (index < to_index && head != NULL)
	{
		index++;
		head = head->next;
	}
	return (head);
}
