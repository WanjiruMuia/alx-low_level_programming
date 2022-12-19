#include "main.h"
/**
* print_rev - This funtion prints a reverse string
* @s: This is the input string
* return: 0
*/
void print_rev(char *s)
{  
	int index;
	
	for (index = 0; s[index] != '\0'; index++)
	     =
	for (index = index - 1; s[index] != '\0'; index--)
	{
		_putchar(s[index]);
	}
	_putchar('n\');
}
