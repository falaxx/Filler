/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmerding <fmerding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:03:02 by fmerding          #+#    #+#             */
/*   Updated: 2018/12/05 19:57:55 by fmerding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_copy(void const *content, size_t content_size)
{
	unsigned char	*c;
	unsigned char	*d;
	void			*cont;

	if (!(cont = ft_memalloc(content_size)))
		return (NULL);
	c = (unsigned char*)content;
	d = (unsigned char*)cont;
	while (*c)
	{
		*(d++) = *(c++);
	}
	return (cont);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		new->content = ft_copy(content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
