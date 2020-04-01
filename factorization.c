/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 18:34:17 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/01 19:05:38 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**
** print number.
** Zero value is unnecessary.
** It is not a prime number.
**
*/

void	ft_put_nbr(unsigned int n)
{
	unsigned char	c;

	if (n == 0)
		return ;
	else
		ft_put_nbr(n / 10);
	c = n % 10 +'0';
	write(1, &c, 1);
}

/*
**
** atoui
** if value > MAXUNIT or value <= 2 or value is not a number,
** return 0
** else return number;
**
*/

unsigned int	str_to_number(const char *str)
{
	unsigned long long	answer;
	unsigned int		i;
	
	i = 0;
	answer = 0;
	while (str[i])
	{
		if(str[i] < '0' || str[i] > '9')
		{
			write(1, "error : Please enter positive numbers only.\n", 44);
			return (0);
		}
		answer = answer * 10 + (str[i] - '0');
		if (answer > 4294967295)
		{
			write(1, "error : The number must be less than 4294967296\n", 48);
			return (0);
		}
		i++;
	}
	if (answer == 1)
		write(1, "error : 1 is an invalid value.\n", 31);
	else if (answer == 0 && i != 0)
		write(1, "error : 0 is an invalid value.\n", 31);
	return (answer == 1 ? 0 : answer);
}

/*
**
** sqrt_number
** 65535 can be expressed in 16 bits.
**
*/

unsigned int	sqrt_number(unsigned int n)
{
	unsigned		i;
	unsigned int	base;
	unsigned int	add;

	i = 0;
	base = 32768;
	add = base /2 ;
	if (4294836225 < n)
		return (65535);
	while (i != 16)
	{
		if (base * base > n)
			base -= add;
		else if (base * base < n)
			base += add;
		else if (base * base == n)
			return (base);
		add /= 2;
		i++;
	}
	return (base * base < n ? base + 1 : base);
}

/*
**
** find_prime_number
**
*/

void	find_prime_number(char *check, unsigned int n_sqrt, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 2;
	while (i <= n_sqrt)
	{
		j = 2;
		if (check[i] == 0 && n % i == 0)
		{
			ft_put_nbr(i);
			while (n % i == 0)
				n /= i;
			if (n != 1)
				write(1, " ", 1);
		}
		while (j * i <= n_sqrt && check[i] == 0)
		{
			check[j * i] = 1;
			j++;
		}
		i++;
	}
	if (n != 1)
		ft_put_nbr(n);
	write(1, "\n", 1);
}

/*
**
** (65536)^2 -1== 4294967295(MAXUNIT)
**
*/

int		main(int argv, char *argc[])
{
	unsigned char	check[65536];
	unsigned int	number;
	unsigned int	i;

	if (argv != 2 || !(number = str_to_number(argc[1])))
	{	
		if (argv != 2)
			write(1, "error : Please enter only one argument.\n", 40);
		else if (argc[1][0] == '\0')
			write(1, "error : There are no values.\n", 29);
		return (-1);
	}
	else if (number == 2 || number == 3 || number == 5 || number == 7)
	{
		ft_put_nbr(number);
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (i < 65536)
		check[i++] = 0;
	find_prime_number(check, sqrt_number(number), number);
}
