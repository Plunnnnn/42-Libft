#include "libft.h"


void *ft_memcpy(void *dest, const void *src,size_t n)
{
	unsigned long int	i;
	char	*strd;
	char	*srcd;
	
	strd = (char *)dest;
	srcd = (char *)src;
	i = -1;
	while (++i < n)
		strd[i] = srcd[i];
	return (dest);

	
}
/*
#include <stdio.h>
#include <stddef.h>

int main(){
	char	str[] = "ca marche le frere";
	char	dest[18];
	ft_memcpy(dest, str, 18);
	printf("%s", dest);
}
*/