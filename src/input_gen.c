#include "push_swap.h"
#include "fcntl.h"

int is_not_duplicated(int *arr, int num, int max_iter);

int myRand ()  // Generate a 4 digit pseudo-random integer 
{
  static int next = 3251 ; // Anything you like here - but not 
                           // 0000, 0100, 2500, 3792, 7600, 
                           // 0540, 2916, 5030 or 3009. 
  next = ((next * next) / 100 ) % 10000 ;
  return next ; 
} 
 
int *myRandInRange()  // max-min must be < 10000
{
    int min;
    int max;
    int *arr;
    int num;
    int i;

    int k;
    char    *str;
    int fd;


    min = -99;
    max = 20;
    i = min;
    k = 0;
    
    arr = malloc(sizeof(int *) * max - 1);
	arr[0] = 0;
    //fd = open("input2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0766);
    while (i < max)
    {
		num = myRand() % (max + 1 - min) + min;

		if (is_not_duplicated(arr, num, k))
		{
			arr[k] = num;
			k++;
		}
		// str = ft_itoa(num);
		// write(fd, str, ft_strlen(str));
		// write(fd, "\n", 1);
		// str = NULL;

		i++;
	}
	return (arr);
}

int is_not_duplicated(int *arr, int num, int max_iter)
{
	int j;

	j = 0;
	while (j <= max_iter)
	{
		if (arr[j] == num)
		{
			return (0);
		}
		j++;
	}
	return (1);
}