#include "push_swap.h"
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
void    push_new_node(t_node **head_a, long int data);
void    print_node(t_node *stack);
void    add_back(t_node *head, long int data);

t_stack    *alloc_stacks(int argc, char **argv)
{
    char 		*ptr;
    long int 	ret;
    int 		i;
	t_stack		*stack;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	stack->b = (t_node *)malloc(sizeof(t_node));
	ptr = NULL;
	ret = ft_strtol(argv[i], &ptr, 10);
	stack->a->data = ret;
	stack->a->next = NULL;
	stack->b->data = 0;
	stack->b->next = NULL;
	i++;
	while (argv[i])
	{
		ptr = NULL;
		ret = ft_strtol(argv[i], &ptr, 10);
		add_back(stack->a, ret);
		add_back(stack->b, 0);
		i++;
	}
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
		add_back(stack->a, arr[i]);
		add_back(stack->b, 0);
		i++;
	}
	return (stack);
}

void    add_back(t_node *head, long int data)
{
    t_node *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = (t_node *)malloc(sizeof(t_node));
	current->next->data = data;
	current->next->next = NULL;
}

void    push_new_node(t_node **head_a, long int data)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = *head_a;
	*head_a = new_node;
}

int	pop_node(t_node **head)
{
	int	ret;
	t_node	*next_node;

	ret = -1;
	if (*head == NULL)
		return (ret);
	next_node = (*head)->next;
	ret = (*head)->data;
	free(*head);
	*head = next_node;
	return (ret);
}

void    print_args(t_node *stack)
{
	t_node *current;

	current = stack;
    while (current != NULL)
    {
	    printf("%d\n",current->data);
        current = current->next;
	}
}

void    print_both_stacks(t_stack *stack)
{
	t_node *current_a;
	t_node *current_b;

	current_a = stack->a;
	current_b = stack->b;
	printf("|A|\t|B|\n");
    while (current_a != NULL && current_b != NULL)
    {
	    printf(" %d \t %d\n",current_a->data, current_b->data);
        current_a = current_a->next;
		current_b = current_b->next;
	}
}
