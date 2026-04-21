#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{
}

searchable_tree_bag::~searchable_tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& that) : tree_bag(that) 
{
}

searchable_tree_bag&	searchable_tree_bag::operator=(const searchable_tree_bag& that) 
{
	if (this != &that)
		tree_bag::operator=(that);
	return (*this);
}

bool	searchable_tree_bag::has_node(node *node, int n)
{
	if (node == NULL)
		return (false);
	if (n == node->value)
		return (true);
	if (n < node->value)
		return (has_node(node->l, n));
	return (has_node(node->r, n));
}

bool	searchable_tree_bag::has(int n) const
{
	return (has_node(tree, n));
}
