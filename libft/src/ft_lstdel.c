/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:03:32 by fmerding          #+#    #+#             */
/*   Updated: 2018/11/19 16:41:10 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *,
size_t))
{
	t_list *tmp;
	t_list *tmp2;

	tmp = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	tmp2 = tmp;
	while (tmp)
	{
		tmp = tmp2->next;
		del(tmp2->content, tmp2->content_size);
		free(tmp2);
		tmp2 = tmp;
	}
}
