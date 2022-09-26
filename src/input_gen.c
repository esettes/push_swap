#include "libft.h"
#include "fcntl.h"
int myRand ()  // Generate a 4 digit pseudo-random integer 
{
  static int next = 3251 ; // Anything you like here - but not 
                           // 0000, 0100, 2500, 3792, 7600, 
                           // 0540, 2916, 5030 or 3009. 
  next = ((next * next) / 100 ) % 10000 ;
  return next ; 
} 
 
void myRandInRange()  // max-min must be < 10000
{
    int min;
    int max;
    int num;
    int i;
    char    *str;
    int fd;


    min = -99;
    max = 23;
    i = min;
    num = myRand() % (max + 1 - min) + min;
    fd = open("input2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0766);
    while (i < max)
    {
        num = myRand();
        str = ft_itoa(num);
        //str[i]
        printf("%s \n", str);
        write(fd, str, ft_strlen(str));
        write(fd, "\n", 1);
        str = NULL;
        i++;
    }
    close(fd);
    
  return ;
}