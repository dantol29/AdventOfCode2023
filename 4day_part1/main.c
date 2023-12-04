#include "get_next_line.h"
#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	if (n)
		return (s1[i] - s2[i]);
	else
		return (0);
}

static int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_new(int size, int off, int n, char *new)
{
	while (size > off)
	{
		new[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		off;
	int		size;
	char	*new;

	off = 0;
	size = ft_get_size(n);
	new = (char *)malloc(sizeof(char) * size + 1);
	if (new == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		new[0] = '-';
		new[1] = '2';
		n = 147483648;
		off = 2;
	}
	if (n < 0)
	{
		new[0] = '-';
		off = 1;
		n = -n;
	}
	ft_fill_new(size, off, n, new);
	new[size] = '\0';
	return (new);
}

int	check_sum(char **numbers, char *sum)
{
	int	i = 0;

	while (i < 10)
	{
		if (ft_strncmp(numbers[i], sum, 4) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	solve(char *line)
{
	int	i = 0;
	int	j = 0;
	char	**numbers;
	int	sum = 0;
	int	result = 0;
	
	numbers = malloc(sizeof(char *) * 10);
	while (line[i] != ':')
			i++;
	while (line[i] != '|')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			sum = 0;
			while (line[i] >= '0' && line[i] <= '9')
			{
				sum = (sum * 10) + (line[i] - '0'); 
				i++;
			}
			numbers[j] = ft_itoa(sum);
			j++;
		}
		i++;
	}
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			sum = 0;
			while (line[i] >= '0' && line[i] <= '9')
			{
				sum = (sum * 10) + (line[i] - '0'); 
				i++;
			}
			if (check_sum(numbers, ft_itoa(sum)) == 0 && result > 0)
				result *= 2;
			else if (check_sum(numbers, ft_itoa(sum)) == 0 && result == 0)
				result += 1;
			j++;
		}
		i++;
	}
	return (result);
}

int main()
{
	int		file;
	int		sum = 0;
	char	*line;

	file = open("input.txt", O_RDWR);
	line = get_next_line(file);
	while (line != NULL)
	{
		sum += solve(line);
		line = get_next_line(file);
	}
	printf("%d\n", sum);
	return (0);
}