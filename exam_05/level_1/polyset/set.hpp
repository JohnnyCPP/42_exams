#ifndef SET_HPP
# define SET_HPP

# include "searchable_bag.hpp"

class set 
{
public:

	set(searchable_bag& that);
	~set();
	set(const set& that);
	set&	operator=(const set& that);

	// from bag.hpp
	//
	void	insert(int n);
	void	insert(int* data, int size);
	void	print() const;
	void	clear();

	// from searchable_bag.hpp
	//
	bool	has(int n) const;

	searchable_bag&	get_bag() const;

private:

	// store as a pointer instead of a reference:
	//
	// - supports copy assignment operator
	//
	// - the set needs to be copy-constructible and assignable
	//
	// - references cannot be reassigned
	//
	searchable_bag*	bag;

	// declare as private with no implementation:
	//
	// - respects Orthodox Canonical Form
	//
	// - disables default constructor
	//
	set();

};

#endif
