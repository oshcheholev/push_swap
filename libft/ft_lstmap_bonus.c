/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:25:45 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 14:50:14 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*curr;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr)
	{
		temp = curr->next;
		(del)(curr->content);
		free(curr);
		curr = NULL;
		curr = temp;
	}
	*lst = NULL;
}

static t_list	*lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst != NULL)
	{
		cont = f(lst->content);
		tmp = lstnew(cont);
		if (!tmp)
		{
			del(cont);
			lstclear(&new, (*del));
			return (new);
		}
		lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
/*
void print_elem(void *content) {
    printf("%s ", (char *)content);
}

// Assuming you have a function `del_elem` to free the memory of each element
void del_elem(void *content) {
    free(content);
}

void *add_prefix(void *content) {
    char *prefix = "Prefix_";
    char *str = (char *)content;
    char *result = malloc(strlen(prefix) + strlen(str) + 1);
    if (result != NULL) {
        strcpy(result, prefix);
        strcat(result, str);
    }
    return result;
}
int main() {
    // Creating a linked list with some strings
    t_list *lst = ft_lstnew("Hello");
    ft_lstadd_back(&lst, ft_lstnew("world"));
    ft_lstadd_back(&lst, ft_lstnew("from"));
    ft_lstadd_back(&lst, ft_lstnew("Linked"));
    ft_lstadd_back(&lst, ft_lstnew("List"));

    // Mapping the list to add prefix to each element
    t_list *mapped_list = ft_lstmap(lst, add_prefix, del_elem);

    // Printing the original list
    printf("Original list:\n");
    ft_lstiter(lst, print_elem);
    printf("\n");

    // Printing the mapped list
    printf("Mapped list:\n");
    ft_lstiter(mapped_list, print_elem);
    printf("\n");

    // Freeing memory
    ft_lstclear(&lst, del_elem);
    ft_lstclear(&mapped_list, del_elem);

    return 0;
}*/