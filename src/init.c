#include "push_swap.h"
long 	ft_nodertol(const char *restrict nptr, char **restrict endptr, int base);
void    push_new_node(t_node **head_a, long int data);
void    print_node(t_node *stack);
void    add_back(t_node *head, long int data);

// void    alloc_stacks(int argc, char **argv, t_stack *stack)
// {
//     int         i;
//     char 		*ptr;
//     long int 	ret;
//     t_node        **new_data;
//     t_node        *new_b;

//     i = 1;
//     // if (argc == 1)
//     //     return ;
//     new_data = (t_node **)malloc(sizeof(t_node));
//     // new_a->data = malloc(sizeof(long int) * argc);
//     // new_a->next = stack->a;
//     //stack->a->data = malloc(sizeof(long int) * argc - 1);
//     //stack->a->next = stack->a;
//     while (i < argc)
//     {
//         ptr = NULL;
//         new_data[i] = (t_node *)malloc(sizeof(t_node));
//         ret = ft_nodertol(argv[i], &ptr, 10);
//         new_data[i]->data = ret;
//         new_data[i]->next = NULL;
//         stack->a = new_data[i];
//         printf("%i\n", stack->a->data);
//         i++;
//     }
//     free(new_data);
// }
t_stack    *alloc_stacks(int argc, char **argv)
{
    char 		*ptr;
    long int 	ret;
    int 		i;
	t_stack	*stack;
	t_node 	*head_;
	t_node 	*second_a;
	t_node 	*third_a;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	ptr = NULL;
	ret = ft_strtol(argv[i], &ptr, 10);
	stack->a->data = ret;
	stack->a->next = NULL;


	i++;
	while (argv[i])
	{
		ptr = NULL;
		ret = ft_strtol(argv[i], &ptr, 10);
		add_back(stack->a, ret);
		// if (i == 1)
		// {
		// 	head_->data = ret;
		// 	head_->next = second_a;
		// 	print_node(head_);
		// 	free(head_);
		// }
		// if (i == 2)
		// {
		// 	second_a->data = ret;
		// 	second_a->next = third_a;
		// 	print_node(second_a);
		// 	free(second_a);
		// }
		// if (i == 3)
		// {
		// 	third_a->data = ret;
		// 	third_a->next = NULL;
		// 	print_node(third_a);
		// 	free(third_a);
		// }
		//push_new_node(head_a, ret);
		//printf("%i\n",(*head_a)->data);
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void    print_node(t_node *stack)
{
	printf("%d\n",stack->data);
    stack = stack->next;
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
