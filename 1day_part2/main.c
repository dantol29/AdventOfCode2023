#include "get_next_line.h"
#include <stdio.h>

int	calculate_sum(char *line)
{
	int	i = 0;
	int	first = 0;
	int	second = 0;
	int	len = 0;

	while (i < (int)ft_strlen(line))
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			first = line[i] - '0';
			break;
		}
		if (line[i] == 'o' && line[i + 1] == 'n' && line[i + 2] == 'e')
		{
			first = 1;
			break;
		}
		if (line[i] == 't' && line[i + 1] == 'w' && line[i + 2] == 'o')
		{
			first = 2;
			break;
		}
		if (line[i] == 't' && line[i + 1] == 'h' && line[i + 2] == 'r' && line[i + 3] == 'e' && line[i + 4] == 'e')
		{
			first = 3;
			break;
		}
		if (line[i] == 'f' && line[i + 1] == 'o' && line[i + 2] == 'u' && line[i + 3] == 'r')
		{
			first = 4;
			break;
		}
		if (line[i] == 'f' && line[i + 1] == 'i' && line[i + 2] == 'v' && line[i + 3] == 'e')
		{
			first = 5;
			break;
		}
		if (line[i] == 's' && line[i + 1] == 'i' && line[i + 2] == 'x')
		{
			first = 6;
			break;
		}
		if (line[i] == 's' && line[i + 1] == 'e' && line[i + 2] == 'v' && line[i + 3] == 'e' && line[i + 4] == 'n')
		{
			first = 7;
			break;
		}
		if (line[i] == 'e' && line[i + 1] == 'i' && line[i + 2] == 'g' && line[i + 3] == 'h' && line[i + 4] == 't')
		{
			first = 8;
			break;
		}
		if (line[i] == 'n' && line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == 'e')
		{
			first = 9;
			break;
		}
		i++;
	}
	len = (int)ft_strlen(line);
	while (len >= 0)
	{
		if (line[len] >= '0' && line[len] <= '9')
		{
			if (len == i)
				second = first * 11;
			else
				second = first * 10 + (line[len] - '0');
			break;
		}
		if (line[len - 2] == 'o' && line[len - 1] == 'n' && line[len] == 'e')
		{
			second = first * 10 + 1;
			break;
		}
		if (line[len - 2] == 't' && line[len - 1] == 'w' && line[len] == 'o')
		{
			second = first * 10 + 2;
			break;
		}
		if (line[len - 4] == 't' && line[len - 3] == 'h' && line[len - 2] == 'r' && line[len - 1] == 'e' && line[len] == 'e')
		{
			second = first * 10 + 3;
			break;
		}
		if (line[len - 3] == 'f' && line[len - 2] == 'o' && line[len - 1] == 'u' && line[len] == 'r')
		{
			second = first * 10 + 4;
			break;
		}
		if (line[len - 3] == 'f' && line[len - 2] == 'i' && line[len - 1] == 'v' && line[len] == 'e')
		{
			second = first * 10 + 5;
			break;
		}
		if (line[len - 2] == 's' && line[len - 1] == 'i' && line[len] == 'x')
		{
			second = first * 10 + 6;
			break;
		}
		if (line[len - 4] == 's' && line[len - 3] == 'e' && line[len - 2] == 'v' && line[len - 1] == 'e' && line[len] == 'n')
		{
			second = first * 10 + 7;
			break;
		}
		if (line[len - 4] == 'e' && line[len - 3] == 'i' && line[len - 2] == 'g' && line[len - 1] == 'h' && line[len] == 't')
		{
			second = first * 10 + 8;
			break;
		}
		if (line[len - 3] == 'n' && line[len - 2] == 'i' && line[len - 1] == 'n' && line[len] == 'e')
		{
			second = first * 10 + 9;
			break;
		}
		len--;
	}
	return (second);
}

int main()
{
	int		file;
	int		sum;
	char	*line;

	sum = 0;
	file = open("input.txt", O_RDWR);
	line = get_next_line(file);
	while (line != NULL)
	{
		sum = sum + calculate_sum(line);
		line = get_next_line(file);
		printf("%s\n", line);
	}
	printf("%d\n", sum);
}