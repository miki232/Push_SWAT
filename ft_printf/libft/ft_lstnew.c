/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:57:22 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/19 17:57:33 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *cont)
{
	t_list	*neww;

	neww = malloc(sizeof(t_list));
	if (!neww)
		return (NULL);
	neww->content = cont;
	neww->next = NULL;
	return (neww);
}
