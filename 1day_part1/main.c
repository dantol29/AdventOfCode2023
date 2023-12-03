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