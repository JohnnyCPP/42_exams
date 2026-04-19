#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>
# include <iostream>
# include <sstream>

class bigint
{
private:

	std::string	magnitude;

public:

	bigint();
	~bigint();
	bigint(const bigint& that);
	bigint(const unsigned int n);
	bigint&	operator=(const bigint& that);

	void	setMagnitude(const std::string& magnitude);
	std::string getMagnitude() const;

	bigint operator+(const bigint& that) const;
	bigint& operator+=(const bigint& that);

	bigint& operator++();
	bigint operator++(int);

	bigint operator<<(unsigned int n) const;
	bigint operator>>(unsigned int n) const;

	bigint& operator<<=(unsigned int n);
	bigint& operator>>=(unsigned int n);

	bigint operator<<(const bigint& that) const;
	bigint operator>>(const bigint& that) const;

	bigint& operator<<=(const bigint& that);
	bigint& operator>>=(const bigint& that);

	bool operator==(const bigint& that) const;
	bool operator!=(const bigint& that) const;

	bool operator<(const bigint& that) const;
	bool operator>(const bigint& that) const;

	bool operator<=(const bigint& that) const;
	bool operator>=(const bigint& that) const;
};

std::ostream&	operator<<(std::ostream& out, const bigint& value);

#endif
