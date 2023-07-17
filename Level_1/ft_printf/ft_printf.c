/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernede <mbernede@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:02:36 by mbernede          #+#    #+#             */
/*   Updated: 2022/10/25 14:15:52 by mbernede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static char	*itoacall(unsigned long nb, char type)
{
	char	*ptr;

	if (type == 'u')
		ptr = ft_itoahuge(nb);
	else
		ptr = ft_itoa(nb);
	if (!ptr)
		return (NULL);
	return (ptr);
}

static int	hexa(int *result, char type, unsigned long nb)
{
	char				*basecapx;
	char				*basex;

	basecapx = "0123456789ABCDEF";
	basex = "0123456789abcdef";
	if (nb >= 16)
		hexa(result, type, nb / 16);
	if (type == 'X')
		*result += write(1, &basecapx[(nb % 16)], 1);
	else
		*result += write(1, &basex[(nb % 16)], 1);
	return (0);
}

static int	numbers(int *result, va_list liste, char type)
{
	unsigned long	nb;
	char			*ptr;

	if (type == 'p')
		nb = va_arg(liste, unsigned long);
	else
		nb = va_arg(liste, unsigned int);
	if (ft_strchr("diu", type))
	{
		ptr = itoacall(nb, type);
		if (!ptr)
			return (-1);
		ft_putstr_fd(ptr, 1);
		*result += ft_strlen(ptr);
		free(ptr);
	}
	else
	{
		if (type == 'p')
			*result += write(1, "0x", 2);
		hexa(result, type, nb);
	}
	return (0);
}

static int	function_choice(int *result, char type, va_list liste)
{
	if (type == 's' || type == 'c')
		chars(result, type, liste);
	else if (type == '%')
		*result += write(1, "%", 1);
	else if (ft_strchr("pdiuxX", type))
		numbers(result, liste, type);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	liste;
	int		i;
	int		result;

	va_start(liste, s);
	i = 0;
	result = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			++i;
			if (s[i] == 0)
				return (result);
			if (!function_choice(&result, s[i], liste))
				result += write(1, &s[i], 1);
		}
		else
			result += write(1, &s[i], 1);
		++i;
	}
	va_end(liste);
	return (result);
}

// int main()
// {
// 	printf("%d\n",printf("hello %!qtoi %m%% %\0ok"));
// 	printf("%d\n",ft_printf("hello %!qtoi %m%% %\0 ok"));
// 	return 0;
// }