#include "push_swap.h"

void    f_reverse_rotate(t_node **head, int print, int stack)
{
    t_node *tmp;
    t_node *last;

    if (*head == NULL || (*head)->next == NULL)
        return ;
    tmp = *head;
    while (tmp->next)
    {
        last = tmp;
        tmp = tmp->next;
    }
    last->next = NULL;
    tmp->next = *head;
    *head = tmp;
    if (print)
    {
        if (stack == 1)
            ft_putendl_fd(VIOLET_, "rra", 1);
        else if (stack == 2)
            ft_putendl_fd(VIOLET_, "rrb", 1);
    }
}

void	f_rotate(t_node **head, int print, int stack)
{
	long int	aux;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	aux = pop_node(head);
	add_back(*head, aux);
	if (print)
	{
		if (stack == 1)
			ft_putendl_fd(VIOLET_, "ra", 1);
		else if (stack == 2)
			ft_putendl_fd(VIOLET_, "rb", 1);
	}
}
