// #include "ft_printf.h"

// char	*g_base;

// int		ft_chk(void)
// {
// 	int chk[256];
// 	int index;

// 	index = 0;
// 	while (index < 256)
// 		chk[index++] = 0;
// 	index = 0;
// 	while (g_base[index] != '\0')
// 	{
// 		if (chk[(int)g_base[index]] || g_base[index] == '+'
// 				|| g_base[index] == '-')
// 			return (0);
// 		chk[(int)g_base[index++]] = 1;
// 	}
// 	return (1);
// }

// int		ft_length(void)
// {
// 	int index;

// 	index = 0;
// 	while (g_base[index] != '\0')
// 		index++;
// 	return (index);
// }

// void	ft_putnbr_base(int nbr, char *base)
// {
// 	int			length;
// 	long long	temp;

// 	temp = nbr;
// 	g_base = base;
// 	length = ft_length();
// 	if (length < 2 || !ft_chk())
// 	{
// 		return ;
// 	}
// 	if (temp < 0)
// 	{
// 		temp *= -1;
// 		write(1, "-", 1);
// 	}
// 	ft_print(temp / length, length);
// 	write(1, &g_base[temp % length], 1);
// }