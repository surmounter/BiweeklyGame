#include "Point.h"

Point::Point(float x, float y) : _x(x), _y(y)
{

}

Point::~Point()
{
}

std::ostream & operator<<(std::ostream & os, const Point & p)
{
	os << "point : " << "(" << p._x << "," << p._y << ")" << std::endl;
	return os;
}
