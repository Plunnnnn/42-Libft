int ft_isprint(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && i < 16)
	{
		if (str[i] <= 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}