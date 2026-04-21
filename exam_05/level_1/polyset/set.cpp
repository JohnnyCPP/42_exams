#include "set.hpp"

set::set(searchable_bag& that) : bag(&that)
{
}

set::~set()
{
}

set::set(const set& that) : bag(that.bag)
{
}

set&	set::operator=(const set& that)
{
	if (this != &that)
		bag = that.bag;
	return (*this);
}

void	set::insert(int n)
{
	bag->insert(n);
}

void	set::insert(int* data, int size)
{
	bag->insert(data, size);
}

bool	set::has(int n) const
{
	return (bag->has(n));
}

void	set::print() const
{
	bag->print();
}

void	set::clear()
{
	bag->clear();
}

searchable_bag&	set::get_bag() const
{
	return (*bag);
}
