#include "libft.h"

void	bzero(void *s,size_t n)
{
	unsigned long int	i;
	char *str;

	str = (char *)s;
	i = -1;
	while (++i <= n)
		str[i] = 0;
}