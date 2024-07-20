#include "libft.h"


void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *)s;
	i = 0;
	while(i <= n && str)
	{
		if (*str == c)
			return (str);
		str++;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <stddef.h>
int main(){

	char	str[] = "Eu vou encontrar um ponto . Ca esta ele!";
	char	c = '.';
	printf("%p", ft_memchr(&str, c, 40));
}
*/