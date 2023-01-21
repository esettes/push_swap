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

t_moves	*search_num_movements(void)
{
	
}
