#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag()
{
}

searchable_array_bag::~searchable_array_bag()
{
}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& that) : array_bag(that)
{
}

searchable_array_bag&	searchable_array_bag::operator=(const searchable_array_bag& that)
{
	if (this != &that)
		array_bag::operator=(that);
	return (*this);
}

bool	searchable_array_bag::has(int n) const
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (data[i] == n)
			return (true);
		i ++;
	}
	return (false);
}
