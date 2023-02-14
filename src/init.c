#include "push_swap.h"
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
void    push_new_node(t_node **head_a, long int data);
void    print_node(t_node *stack);

t_stack    *alloc_stacks(int argc, char **argv)
{
	char 		*ptr;
	long int 	ret;
	int 		i;
	t_stack		*stack;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	// stack->b = (t_node *)malloc(sizeof(t_node));
	stack->b = NULL;
	ptr = NULL;
	ret = ft_strtol(argv[i], &ptr, 10);
	stack->a->data = ret;
	stack->a->next = NULL;
	stack->is_even = 0;
	// stack->b->data = '\0';
	// stack->b->index = '\0';
	// stack->b->next = NULL;
	i++;
	while (argv[i])
	{
		ptr = NULL;
		ret = ft_strtol(argv[i], &ptr, 10);
		add_value_back(&stack->a, ret);
		//add_back(stack->b, 0);
		i++;
	}
	i--;
	stack->elements = i;
	if (i % 2 == 0)
		stack->is_even = 1;
	return (stack);
}

t_stack		*alloc_stacks_arr(int argc, int *arr)
{
	int 		i;
	t_stack		*stack;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	stack->b = (t_node *)malloc(sizeof(t_node));
	stack->a->data = arr[i];
	stack->a->next = NULL;
	stack->b->data = 0;
	stack->b->next = NULL;
	i++;
	while (arr[i])
	{
		add_value_back(&stack->a, arr[i]);
		add_value_back(&stack->b, 0);
		i++;
	}
	return (stack);
}

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

void    print_args(t_node *stack)
{
	t_node *current;

	current = stack;
	while (current != NULL)
	{
		printf("%ld\n",current->data);
		current = current->next;
	}
}

void	print_both_stacks(t_stack *stack, int i, int j)
{
	t_node *current_a;
	t_node *current_b;
	int		aux;

	#if PRINT_
	printf("\033c");
	current_a = stack->a;
	current_b = stack->b;
	aux = 0;
	printf("|A|\t|B|\n");
	while (aux <= stack->elements + 1)
	{
		if (current_a && current_b)
		{
			printf(" %ld \t %ld\n",current_a->data, current_b->data);
			current_a = current_a->next;
			current_b = current_b->next;
			aux++;
		}
		else if (current_b)
		{
			printf("   \t %ld\n", current_b->data);
			current_b = current_b->next;
		}
		else if (current_a)
		{
			printf(" %ld \t  \n",current_a->data);
			current_a = current_a->next;
		}
		aux++;
	}
	printf("i: \t%i\n", i);
	printf("j: \t%i\n", j);
	usleep(190000);
	#endif
}
