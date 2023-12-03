#include "get_next_line.h"
#include <stdio.h>

int	check_set(char *line, int len)
{
	int	sum;
	int green = 0;
	int	blue = 0;
	int	red = 0;

	while (line[len] != ':' && len > 6)
	{
		if (line[len] >= '0' && line[len] <= '9')
		{
			if (line[len - 1] >= '0' && line[len - 1] <= '9')
				sum = (line[len - 1] - '0') * 10 + (line[len] - '0');
			else
				sum = line[len] - '0';
			if (line[len + 2] == 'b' && sum > blue)
				blue = sum;
			else if (line[len + 2] == 'g' && sum > green)
				green = sum;
			else if (line[len + 2] == 'r' && sum > red)
				red = sum;
			if (line[len - 1] >= '0' && line[len - 1] <= '9')
				len--;
		}
		len--;
	}
	printf("%d red %d green %d blue\n", red, green, blue);
	return (red * blue * green);
}

int	valid_game(char *line)
{
	int	len;
	int	temp;

	len = ft_strlen(line) - 1;
	temp = check_set(line, len);
	return (temp);
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
		printf("%s\n", line);
		sum = sum + valid_game(line);
		line = get_next_line(file);
	}
	printf("\n\n\n%d\n", sum);
}