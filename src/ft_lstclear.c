/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:15:11 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:04:39 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Deletes and frees the given 'lst' node and all consecutive nodes
within that node, using the 'del' function and free(3).
At the end, the list pointer must be NULL.*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*aux;

	if (!lst || !(*lst) || !del)
		return ;
	aux = (*lst);
	temp = aux;
	while (temp != NULL)
	{
		temp = temp->next;
		ft_lstdelone(aux, del);
		aux = temp;
	}
	*lst = NULL;
}
