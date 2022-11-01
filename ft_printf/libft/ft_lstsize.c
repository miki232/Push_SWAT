/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:35:01 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/21 14:37:49 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
// #include <stdio.h>
// int main(void)
// {
// 	t_list *elem1;
// 	t_list *elem2;
// 	t_list *elem3;
// 	char *s = "dribbel";
// 	char *t = "donut";
// 	char *f = "draak";
// 	elem1 = ft_lstnew(ft_strdup(s));
// 	elem2 = ft_lstnew(ft_strdup(t));
// 	elem3 = ft_lstnew(ft_strdup(f));
// 	elem1->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = NULL;
// 	printf("%d", ft_lstsize(elem1));
// 	return(0);
// }
