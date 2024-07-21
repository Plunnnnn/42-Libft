#include "libft.h"

int		ft_memcmp(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n < 1)
	{
		return (0);
	}
	while ((*str1 == *str2 && *str1 && *str2) && i < n - 1)
	{
		str1++;
		str2++;
		i++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}

/*
#include <stdio.h>
#include <stddef.h>

int main(){
	char	str[] = "ca marche le frere";
	char	dest[] = "ca marche le frere";
	
	printf("%d", ft_memcmp(dest, str, 19));
}
*/