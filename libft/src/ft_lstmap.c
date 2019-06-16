/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:04:07 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/19 17:29:33 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	lst = lst->next;
	res = tmp;
	while (lst)
	{
		tmp2 = f(lst);
		tmp->next = tmp2;
		tmp = tmp2;
		lst = lst->next;
	}
	tmp->next = NULL;
	return (res);
}
