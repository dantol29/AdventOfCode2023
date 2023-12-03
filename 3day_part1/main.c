#include "get_next_line.h"
#include <stdio.h>


int	get_number(char **table, int row, int column)
{
	int	num = 0;

	while (table[row][column] >= '0' && table[row][column] <= '9')
		column--;
	column++;
	while (table[row][column] >= '0' && table[row][column] <= '9')
	{
		num = (num * 10)+ (table[row][column] - '0');
		column++;
	}
	printf("%d\n", num);
	return (num);
}

void	print_table(char **table, int lcount)
{
	int	i;
	int	j;

	i = 0;
	while (i < lcount)
	{
		j = 1;
		while (table[i][j])
		{
			write(1, &table[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	solve(char **table)
{
	int	i = 0;
	int	j = 0;
	int	status = 0;
	int	sum = 0;
	while (i < 140)
	{
		j = 0;
		while (j < 140)
		{
			status = 0;
			if ((table[i][j] >= '0' && table[i][j] <= '9') && i == 0)
			{
				if ((table[i][j - 1] >= 33 && table[i][j - 1] <= 47 && table[i][j - 1] != 46) || (table[i][j - 1] >= 58 && table[i][j - 1] <= 64 && table[i][j - 1] != 46))
					status = 1;
				else if ((table[i][j + 1] >= 33 && table[i][j + 1] <= 47 && table[i][j + 1] != 46) || (table[i][j + 1] >= 58 && table[i][j + 1] <= 64 && table[i][j + 1] != 46))
					status = 1;
				else if ((table[i + 1][j] >= 33 && table[i + 1][j] <= 47 && table[i + 1][j] != 46) || (table[i + 1][j] >= 58 && table[i + 1][j] <= 64 && table[i + 1][j] != 46))
					status = 1;
				else if ((table[i + 1][j - 1] >= 33 && table[i  + 1][j - 1] <= 47 && table[i + 1][j - 1] != 46) || (table[i + 1][j - 1] >= 58 && table[i + 1][j - 1] <= 64 && table[i + 1][j - 1] != 46))
					status = 1;
				else if ((table[i + 1][j + 1] >= 33 && table[i + 1][j + 1] <= 47 && table[i + 1][j + 1] != 46) || (table[i + 1][j + 1] >= 58 && table[i + 1][j + 1] <= 64 && table[i + 1][j + 1] != 46))
					status = 1;
				if (status == 1)
					sum = sum + get_number(table, i, j);
				while (table[i][j] >= '0' && table[i][j] <= '9' && status == 1)
					j++;
			}
			else if ((table[i][j] >= '0' && table[i][j] <= '9') && i == 139)
			{
				if ((table[i][j - 1] >= 33 && table[i][j - 1] <= 47 && table[i][j - 1] != 46) || (table[i][j - 1] >= 58 && table[i][j - 1] <= 64 && table[i][j - 1] != 46))
					status = 1;
				else if ((table[i][j + 1] >= 33 && table[i][j + 1] <= 47 && table[i][j + 1] != 46) || (table[i][j + 1] >= 58 && table[i][j + 1] <= 64 && table[i][j + 1] != 46))
					status = 1;
				else if ((table[i - 1][j] >= 33 && table[i - 1][j] <= 47 && table[i - 1][j] != 46) || (table[i - 1][j] >= 58 && table[i - 1][j] <= 64 && table[i - 1][j] != 46))
					status = 1;
				else if ((table[i - 1][j + 1] >= 33 && table[i - 1][j + 1] <= 47 && table[i - 1][j + 1] != 46) || (table[i - 1][j + 1] >= 58 && table[i - 1][j + 1] <= 64 && table[i - 1][j + 1] != 46))
					status = 1;
				else if ((table[i - 1][j - 1] >= 33 && table[i - 1][j - 1] <= 47 && table[i - 1][j - 1] != 46) || (table[i - 1][j - 1] >= 58 && table[i - 1][j - 1] <= 64 && table[i - 1][j - 1] != 46))
					status = 1;
				if (status == 1)
					sum = sum + get_number(table, i, j);
				while (table[i][j] >= '0' && table[i][j] <= '9' && status == 1)
					j++;
			}
			else if (table[i][j] >= '0' && table[i][j] <= '9')
			{
				if ((table[i][j - 1] >= 33 && table[i][j - 1] <= 47 && table[i][j - 1] != 46) || (table[i][j - 1] >= 58 && table[i][j - 1] <= 64 && table[i][j - 1] != 46))
					status = 1;
				else if ((table[i + 1][j] >= 33 && table[i + 1][j] <= 47 && table[i + 1][j] != 46) || (table[i + 1][j] >= 58 && table[i + 1][j] <= 64 && table[i + 1][j] != 46))
					status = 1;
				else if ((table[i + 1][j - 1] >= 33 && table[i  + 1][j - 1] <= 47 && table[i + 1][j - 1] != 46) || (table[i + 1][j - 1] >= 58 && table[i + 1][j - 1] <= 64 && table[i + 1][j - 1] != 46))
					status = 1;
				else if ((table[i][j + 1] >= 33 && table[i][j + 1] <= 47 && table[i][j + 1] != 46) || (table[i][j + 1] >= 58 && table[i][j + 1] <= 64 && table[i][j + 1] != 46))
					status = 1;
				else if ((table[i + 1][j + 1] >= 33 && table[i + 1][j + 1] <= 47 && table[i + 1][j + 1] != 46) || (table[i + 1][j + 1] >= 58 && table[i + 1][j + 1] <= 64 && table[i + 1][j + 1] != 46))
					status = 1;
				else if ((table[i - 1][j] >= 33 && table[i - 1][j] <= 47 && table[i - 1][j] != 46) || (table[i - 1][j] >= 58 && table[i - 1][j] <= 64 && table[i - 1][j] != 46))
					status = 1;
				else if ((table[i - 1][j + 1] >= 33 && table[i - 1][j + 1] <= 47 && table[i - 1][j + 1] != 46) || (table[i - 1][j + 1] >= 58 && table[i - 1][j + 1] <= 64 && table[i - 1][j + 1] != 46))
					status = 1;
				else if ((table[i - 1][j - 1] >= 33 && table[i - 1][j - 1] <= 47 && table[i - 1][j - 1] != 46) || (table[i - 1][j - 1] >= 58 && table[i - 1][j - 1] <= 64 && table[i - 1][j - 1] != 46))
					status = 1;
				if (status == 1)
					sum = sum + get_number(table, i, j);
				while (table[i][j] >= '0' && table[i][j] <= '9' && status == 1)
					j++;
			}
			j++;
		}
		i++;
	}
	return (sum);
}

int main()
{
	int		file;
	int		i = 0;
	char	**table;

	table = (char **)malloc(sizeof(char *) * 140);
	file = open("input.txt", O_RDWR);
	table[i] = get_next_line(file);
	while (table[i] != NULL)
	{
		i++;
		table[i] = get_next_line(file);
	}
	//print_table(table, 10);
	printf("\n\n\n%d\n", solve(table));
}