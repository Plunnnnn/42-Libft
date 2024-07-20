int	ft_atoi(char *str)
{
	int	rez;
	int	s;

	rez = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	if (s > 1)
		return (0);
	while ((*str >= '0' && *str <= '9'))
	{
		rez *= 10;
		rez += (*str - '0');
		str++;
	}
	return (s * rez);
}