#include "push_swap.h"

int		get_min_value(t_node *head)
{
	int		min;

	min = head->data;
	while (head)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}

void	counting_sort()
{
	// obtain range between min val and max

	// obtain if head->val exists in range and save in index

	// sum 'existing' values for each index

	// move 1 position each summed values
	
	int	*arr_cont;
	int min;
	int max;

}