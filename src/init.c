#include "push_swap.h"
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);

void    alloc_stacks(int argc, char **argv, t_stack *stack)
{
    int         i;
    char 		*ptr;
    long int 	ret;
    t_st        *new_a;
    t_st        *new_b;

    i = 1;
    // if (argc == 1)
    //     return ;
    new_a = (t_st *)malloc(sizeof(t_st));
    new_a->item = malloc(sizeof(long int) * argc);
    new_a->next = stack->a;
    while (i < argc)
    {
        ptr = NULL;
        ret = ft_strtol(argv[i], &ptr, 10);
        new_a->item[i - 1] = ret;
        printf("%i\n", new_a->item[i - 1]);
        stack->a = new_a;
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
        stack->a = stack->a->next;
		i++;
	}
}
