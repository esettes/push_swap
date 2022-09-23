#include "push_swap.h"
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);

/*
void    alloc_stacks_1(int argc, char **argv, t_stack *stack)
{
    int         i;
    char 		*ptr;
    long int 	ret;

    i = 1;
    // if (argc == 1)
    //     return ;
    stack->a = (int *)malloc(sizeof(int) * (argc));
    stack->b = (int *)malloc(sizeof(int) * (argc));
    while(i < argc)
    {
        ptr = NULL;
        ret = ft_strtol(argv[i], &ptr, 10);
        stack->a[i] = ret;
        //printf("%i\n", stack->a[i]);
        i++;
    }
}
*/

void    alloc_stacks(int argc, char **argv, t_stack *stack)
{
    int         i;
    char 		*ptr;
    long int 	ret;

    i = 1;
    // if (argc == 1)
    //     return ;
    //stack = (t_stack *)malloc(sizeof(t_stack));
    stack->a = (int *)malloc(sizeof(int) * (argc));
    stack->b = (int *)malloc(sizeof(int) * (argc));
    //while(i < argc)
    while (i < argc)
    {
        ptr = NULL;
        ret = ft_strtol(argv[i], &ptr, 10);
        stack->a->item = ret;
        stack->a = stack->a->next;
        i++;
    }
}

void    print_args(int pos, t_stack *stack)
{
    int i;

    i = 1;
    while (i < pos)
    {
	    printf("%i\n",stack->a->item[i]);
		i++;
	}
}
