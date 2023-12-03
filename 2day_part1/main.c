#include "get_next_line.h"
#include <stdio.h>
# define RED 12
# define GREEN 13
# define BLUE 14
int	check_set(char *line, int len)
{
	int	sum;

	while (line[len] != ':' && len > 6)
	{
		if (line[len] >= '0' && line[len] <= '9')
		{
			if (line[len - 1] >= '0' && line[len - 1] <= '9')
				sum = (line[len - 1] - '0') * 10 + (line[len] - '0');
			else
				sum = line[len] - '0';
			printf("%d\n", sum);
			if (line[len + 2] == 'b' && sum > BLUE)
				return (0);
			else if (line[len + 2] == 'g' && sum > GREEN)
				return (0);
			else if (line[len + 2] == 'r' && sum > RED)
				return (0);
			if (line[len - 1] >= '0' && line[len - 1] <= '9')
				len--;
		}
		len--;
	}
	return (1);
}

int	valid_game(char *line, int index)
{
	int	len;

	len = ft_strlen(line) - 1;
	if (check_set(line, len) == 0)
		return (0);
	else
		return (index);
}

int main()
{
	int		file;
	int		sum;
	int		index;
	char	*line;

	sum = 0;
	index = 1;
	file = open("input.txt", O_RDWR);
	line = get_next_line(file);
	while (line != NULL)
	{
		printf("%s\n", line);
		sum = sum + valid_game(line, index++);
		line = get_next_line(file);
	}
	printf("\n\n\n%d\n", sum);
}