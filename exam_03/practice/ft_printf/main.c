#include <stddef.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	char	*str = "hello%s\n";
	char	*formatted = NULL;
	int	count = ft_printf(str, formatted);
	ft_printf("count=%d\n", count);
	return (0);
}
