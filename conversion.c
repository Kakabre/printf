#include <stdlib.h>
#include "main.h"

/**
 * convert_alpha_numeric - convert digits to char
 * @nb: digit or number
 * @upper: upper case check
 * Return: converted value
 */

int convert_alpha_numeric(int nb, int upper)
{
	if (nb >= 10)
		return (nb - 10 + ((upper) ? 'A' : 'a'));
	else
		return (nb + '0');
}

/**
 * convert_base - convert unsigned from base 10
 * @nb: decimal number
 * @base: base to convert from
 * @upper: upper case check
 * Return: converted number to string
 */

char *convert_base(unsigned long nb, unsigned int base, int upper)
{
	int a = 0;
	char *str;
	unsigned long nbr = nb;

	while (nbr >= base)
	{
		nbr /= base;
		a++;
	}
	str = malloc(sizeof(char) * a + 2);
	if (!str)
		return (0);
	str[a + 1] = '\0';

	while (a >= 0)
	{
		nbr = nb % base;
		str[a] = convert_alpha_numeric(nbr, upper);
		nb /= base;
		a--;
	}
	return (str);
}

/**
 * convert_base_pointer - convert pointer void to ul
 * @p: pointer
 * Return: converted string
 */

char *convert_base_pointer(unsigned long p)
{
	unsigned long adress;
	char *str;

	adress = p;
	if (adress == 0)
		return ("0");
	str = convert_base(adress, 16, 0);
	return (str);
}

/**
 * convert_rot13 - encode using rot13
 * @str: string to encode
 * Return: encoded string
 */

char *convert_rot13(char *str)
{
	int a = 0;
	char *s;
	int size = _strlen_recursion(str);

	s = malloc(sizeof(char) * size + 1);
	if (!s)
		return (0);

	while (str[a])
	{
		if ((str[a] >= 'a' && str[a] <= 'm') || (str[a] >= 'A' && str[a] <= 'M'))
			s[a] = str[a] + 13;
		else if ((str[a] >= 'n' && str[a] <= 'z')
				|| (str[a] >= 'N' && str[a] <= 'Z'))
			s[a] = str[a] - 13;
		else
			s[a] = str[a];
		a++;
	}
	s[a] = '\0';
	return (s);
}
