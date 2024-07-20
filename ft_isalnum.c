#include "libft.h"

int ft_isalnum(int str)
{
	return (ft_isalpha(str) || ft_isdigit(str));
}