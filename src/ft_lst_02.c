/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:40:30 by jose-car          #+#    #+#             */
/*   Updated: 2025/12/03 21:41:30 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Returns the last node in the list.
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*It takes an 'lst' node as a parameter and frees the contents'
memory using the 'del' function given as a parameter,
in addition to freeing the node. The memory in 'next' should not be freed.*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_lst;
	void	*new_content;

	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		temp = ft_lstnew(new_content);
		if (!temp)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}
