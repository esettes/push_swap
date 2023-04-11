#include "push_swap.h"
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
void    push_new_node(t_node **head_a, long int data);

t_stack    *alloc_stacks(int argc, char **argv)
{
	char 		*ptr;
	long int 	ret;
	int 		i;
	t_stack		*stack;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	stack->b = NULL;
	ptr = NULL;
	ret = ft_strtol(argv[i], &ptr, 10);
	stack->a->data = ret;
	stack->a->next = NULL;
	i++;
	while (argv[i])
	{
		ptr = NULL;
		ret = ft_strtol(argv[i], &ptr, 10);
		add_value_back(&stack->a, ret);
		i++;
	}
	i--;
	stack->elements = i;
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

void	print_args(t_node *stack)
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
	printf("MIN VAL: %d \n", stack->min_val);
	printf("MAX VAL: %d \n", stack->max_val);
	printf("Elements: %d \n", stack->elements);
	printf("Bucket range: %d \n", stack->bucket_range);
	printf("\n+ + + + + + + +\n\n");
	printf("|A|\t|B|\n");
	while (aux <= stack->elements + 1)
	{
		if (current_a && current_b)
		{
			printf(" %ld, %i \t %ld, %i\n",current_a->index, current_a->b_index, current_b->index, current_b->b_index);
			current_a = current_a->next;
			current_b = current_b->next;
			aux++;
		}
		else if (current_b)
		{
			printf("   \t %ld, %i\n", current_b->index, current_b->b_index);
			current_b = current_b->next;
		}
		else if (current_a)
		{
			printf(" %ld, %i \t  \n",current_a->index, current_a->b_index);
			current_a = current_a->next;
		}
		aux++;
	}
	//printf("i: \t%i\n", i);
	printf("j: \t%i\n", j);
	printf("b_index: \t%i\n", i);
	usleep(450000);
	#endif
}
