#ifndef SEARCHABLE_TREE_BAG_HPP
# define SEARCHABLE_TREE_BAG_HPP

# include "searchable_bag.hpp"
# include "tree_bag.hpp"
# include <cstddef>

class searchable_tree_bag : public searchable_bag, public tree_bag 
{
public:

	searchable_tree_bag();
	~searchable_tree_bag();
	searchable_tree_bag(const searchable_tree_bag& that);
	searchable_tree_bag&	operator=(const searchable_tree_bag& that);

	virtual bool	has(int n) const;

private:

	static bool	has_node(node* node, int n);
};

#endif
