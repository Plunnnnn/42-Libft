int	ft_isalpha(char *str)
{
	int	i;

	i = 0;
	while(i[str])
	{
		if ((i[str] >= 'A' && i[str] <= 'Z') || (i[str] >= 'a' && i[str] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
