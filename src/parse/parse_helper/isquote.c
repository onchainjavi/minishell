/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isquote.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:59:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 16:59:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isquote(char ch)
{
	if (ch == '\'' || ch == '\"')
		return (1);
	else
		return (0);
}
