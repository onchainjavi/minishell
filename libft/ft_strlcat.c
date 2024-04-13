/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:57:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 14:53:51 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	dlen = 0;
	slen = 0;
	while (dest[dlen] != '\0' && dlen < size)
		dlen++;
	while (src[slen] != '\0')
		slen++;
	while (src[i] != '\0' && i < size - dlen - 1 && dlen < size)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	if (i > 0)
		dest[dlen + i] = '\0';
	return (dlen + slen);
}
