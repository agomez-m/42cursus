#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
int main (void) 
{
	char *str = ft_calloc(SIZE_MAX, SIZE_MAX);
	char *str2 = calloc(SIZE_MAX, SIZE_MAX);
	printf("%d\n", ft_atoi("123"));
	printf("tu  funcion %s\n", str);
	printf("calloc %s\n", str2);
	return (0);
}

