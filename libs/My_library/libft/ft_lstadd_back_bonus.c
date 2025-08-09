/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:18:14 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:30:34 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

void	ft_lstadd_back(t_list **lst, t_list *new_)
{
	t_list	*lst_clone;

	if (!new_)
		return ;
	if (!*lst)
	{
		*lst = new_;
		return ;
	}
	lst_clone = ft_lstlast(*lst);
	lst_clone->next = new_;
}
