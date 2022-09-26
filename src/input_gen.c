#include "push_swap.h"
#include "fcntl.h"

int is_not_duplicated(int *arr, int num);

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
    num = myRand() % (max + 1 - min) + min;
    arr = malloc(sizeof(int) * 125);
    //fd = open("input2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0766);
    while (i < max)
    {
		num = myRand();

		if (is_not_duplicated(arr, num))
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

int is_not_duplicated(int *arr, int num)
{
	int j;

	j = 0;
	while (arr[j])
	{
		if (arr[j] == num)
		{
			return (0);
		}
		j++;
	}
	return (1);
}