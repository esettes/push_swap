/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:30:30 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/22 16:31:04 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_value_back(t_node **head, long int data)
{
	t_node *current;

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_node *)malloc(sizeof(t_node));
	current->next->data = data;
	current->next->next = NULL;
}

void	add_back(t_node **head, t_node *new_node)
{
	t_node *current;

	current = *head;
	if (!current)
	{
		*head = new_node;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	push_new_node(t_node **head_a, long int data)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = data;
	if (head_a)
	{
		new_node->next = *head_a;
		*head_a = new_node;
	}
	else
		new_node->next = NULL;
}

void	add_front(t_node **head_a, t_node *new_node)
{
	t_node	*tmp;

	if ((*head_a))
	{
		tmp = *head_a;
		*head_a = new_node;
		new_node->next = tmp;
	}
	else
	{
		*head_a = new_node;
		return ;
		printf("\n------ no list to add_front ------\n");
	}
}

// int	pop_node(t_node **head)
// {
// 	int	ret;
// 	t_node	*next_node;

// 	ret = -1;
// 	if (*head == NULL)
// 		return (ret);
// 	next_node = (*head)->next;
// 	ret = (*head)->data;
// 	free(*head);
// 	*head = next_node;
// 	return (ret);
// }

t_node	*pop_node(t_node **head)
{
	t_node	*next_node;
	t_node	*popped;

	if (*head == NULL)
		return (NULL);
	popped = *head;
	next_node = (*head)->next;
	popped->next = NULL;
	*head = next_node;
	return (popped);
}
