int ft_isascii(int str)
{
	if (str >= 0 && str <= 127)
		return (str);
	return (0);
}