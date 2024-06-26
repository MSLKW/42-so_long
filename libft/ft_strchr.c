/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxliew <maxliew@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:40:42 by maxliew           #+#    #+#             */
/*   Updated: 2024/06/14 10:35:21 by maxliew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	if (str == NULL)
		return (NULL);
	ptr = (char *)str;
	while (*ptr != '\0' && *ptr != (char)c)
		ptr++;
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}
