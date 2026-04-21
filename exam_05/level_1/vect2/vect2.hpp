#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream>

class vect2 
{
private:

	int	dimensions[2];

public:

	vect2();
	~vect2();
	vect2(const vect2& that);
	vect2(int x, int y);
	vect2&	operator=(const vect2& that);

	int&	operator[](int index);
	const int&	operator[](int index) const;

	vect2&	operator+=(const vect2& that);
	vect2&	operator-=(const vect2& that);
	vect2&	operator*=(const vect2& that);
	vect2&	operator*=(int scalar);

	vect2&	operator++();
	vect2	operator++(int);

	vect2&	operator--();
	vect2	operator--(int);
	
	vect2	operator-() const;
};

vect2	operator+(const vect2& left, const vect2& right);
vect2	operator-(const vect2& left, const vect2& right);
vect2	operator*(const vect2& vector, int scalar);
vect2	operator*(int scalar, const vect2& vector);

bool	operator==(const vect2& left, const vect2& right);
bool	operator!=(const vect2& left, const vect2& right);

std::ostream&	operator<<(std::ostream& stream, const vect2& vector);

#endif
