#include "vect2.hpp"

vect2::vect2() : dimensions()
{
	dimensions[0] = 0;
	dimensions[1] = 0;
}

vect2::~vect2()
{
}

vect2::vect2(const vect2& that)
{
	dimensions[0] = that.dimensions[0];
	dimensions[1] = that.dimensions[1];
}

vect2::vect2(int x, int y)
{
	dimensions[0] = x;
	dimensions[1] = y;
}

vect2&	vect2::operator=(const vect2& that)
{
	if (this != &that)
	{
		dimensions[0] = that.dimensions[0];
		dimensions[1] = that.dimensions[1];
	}
	return (*this);
}

int&	vect2::operator[](int index)
{
	return (dimensions[index]);
}

const int&	vect2::operator[](int index) const
{
	return (dimensions[index]);
}

vect2&	vect2::operator+=(const vect2& that)
{
	dimensions[0] += that.dimensions[0];
	dimensions[1] += that.dimensions[1];
	return (*this);
}

vect2&	vect2::operator-=(const vect2& that)
{
	dimensions[0] -= that.dimensions[0];
	dimensions[1] -= that.dimensions[1];
	return (*this);
}

vect2&	vect2::operator*=(const vect2& that)
{
	dimensions[0] *= that.dimensions[0];
	dimensions[1] *= that.dimensions[1];
	return (*this);
}

vect2&	vect2::operator*=(int scalar)
{
	dimensions[0] *= scalar;
	dimensions[1] *= scalar;
	return (*this);
}

vect2&	vect2::operator++()
{
	dimensions[0] ++;
	dimensions[1] ++;
	return (*this);
}

vect2	vect2::operator++(int)
{
	vect2	original(*this);

	dimensions[0] ++;
	dimensions[1] ++;
	return (original);
}

vect2&	vect2::operator--()
{
	dimensions[0] --;
	dimensions[1] --;
	return (*this);
}

vect2	vect2::operator--(int)
{
	vect2	original(*this);

	dimensions[0] --;
	dimensions[1] --;
	return (*this);
}

vect2	vect2::operator-() const
{
	return (vect2(- dimensions[0], - dimensions[1]));
}

vect2	operator+(const vect2& left, const vect2& right)
{
	vect2	result(left);

	result += right;
	return (result);
}

vect2	operator-(const vect2& left, const vect2& right)
{
	vect2	result(left);

	result -= right;
	return (result);
}

vect2	operator*(const vect2& vector, int scalar)
{
	vect2	result(vector);

	result *= scalar;
	return (result);
}

vect2	operator*(int scalar, const vect2& vector)
{
	return (vector * scalar);
}

bool	operator==(const vect2& left, const vect2& right)
{
	return (left[0] == right[0] && left[1] == right[1]);
}

bool	operator!=(const vect2& left, const vect2& right)
{
	return (!(left == right));
}

std::ostream&	operator<<(std::ostream& stream, const vect2& vector)
{
	stream << "{" << vector[0] << ", " << vector[1] << "}";
	return (stream);
}
