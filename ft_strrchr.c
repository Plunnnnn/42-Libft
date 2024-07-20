#include "libft.h" 

char *ft_strrchr(const char *s, int c)
{
	char *str;
	char *occ;

	str = (char *)s;
	occ = NULL;
	while (*str)
	{
			if (*str == c)
				occ = str;
		str++;	
	}
	return (occ);
}