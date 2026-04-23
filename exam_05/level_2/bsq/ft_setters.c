void	ft_set_cell(char *grid, int row, int col, int width, char cell)
{
	grid[row * width + col] = cell;
}

char	ft_get_cell(char *grid, int row, int col, int width)
{
	return (grid[row * width + col]);
}

void	ft_set_size(int *dp, int row, int col, int width, int size)
{
	dp[row * width + col] = size;
}

int	ft_get_size(int *dp, int row, int col, int width)
{
	return (dp[row * width + col]);
}
