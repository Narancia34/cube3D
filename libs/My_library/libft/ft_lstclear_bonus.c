/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:17:48 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:31:01 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_flag;

	if (!lst || !del)
		return ;
	while (*lst != 0)
	{
		lst_flag = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_flag;
	}
	free(*lst);
	*lst = 0;
}
