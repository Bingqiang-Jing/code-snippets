/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:33:33 by exam              #+#    #+#             */
/*   Updated: 2015/11/24 11:59:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static void	ft_putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";

	if (rem > 1)
		ft_putnbr_hex(octet >> 4, rem - 1);
	write(2, base + (octet % 16), 1);
}

static void	sp_putchar(unsigned char const *ptr)
{
	char const c = *ptr;

	if (' ' <= c && c <= '~')
		write(2, ptr, 1);
	else
		write(2, ".", 1);
}

static void	print_memory(const void *addr, size_t size)
{
	size_t i;
	size_t a;
	unsigned char const *ptr = addr;

	i = 0;
	while (i < size)
	{
        unsigned line_num;
		a = 0;
        line_num = i / 16;
        fprintf(stderr, "0x%08x ", line_num);
		while (a < 16 && a + i < size)
		{
			ft_putnbr_hex(*(ptr + i + a), 2);
            write(2, " ", 1);
		//	if (a % 2)
		//		write(2, " ", 1);
			a++;
		}
		while (a < 16)
		{
			write(2, "  ", 2);
			if (a % 2)
				write(2, " ", 1);
			a++;
		}
		a = 0;
		while (a < 16 && a + i < size)
		{
			sp_putchar(ptr + a + i);
			a++;
		}
		write(2, "\n", 1);
		i += 16;
	}
}
