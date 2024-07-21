#include "libft.h"

int ft_isalnum(int str)
{
	if (ft_isalpha(str) || ft_isdigit(str))
		return (8);
	return (0);
}