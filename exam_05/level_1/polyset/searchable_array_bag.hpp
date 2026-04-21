#ifndef SEARCHABLE_ARRAY_BAG_HPP
# define SEARCHABLE_ARRAY_BAG_HPP

# include "searchable_bag.hpp"
# include "array_bag.hpp"

class searchable_array_bag : public searchable_bag, public array_bag
{
public:

	searchable_array_bag();
	~searchable_array_bag();
	searchable_array_bag(const searchable_array_bag& that);
	searchable_array_bag&	operator=(const searchable_array_bag& that);

	virtual bool	has(int n) const;
};

#endif
