#include "push_swap.h"

int	get_node_position(t_node *lst)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	get_rotate_movements(t_node *lst, int index)
{
	int	pos;

	pos = get_node_position(lst);
	// get node position
	// i - 1

}

int	get_reverse_movements()
{
	
}
