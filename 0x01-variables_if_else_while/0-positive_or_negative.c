#include <stdio.h>
#include <stdlib.h>
#include <time>
/**
 * main - to generate a random number
 *
 * return: Always 0 (Success)
 *
 */
int main(void)
{
	int n;
	stand(time(0)(;
        n = rand() - RAND_MAX / 2;
	if (n >0)
	    printf("%i is positive\n", n);
	else if (n < 0)
	    printf("%i is negative\n", n);
	else 
	   printf("%i is zero\n",);
	return (0);
}
