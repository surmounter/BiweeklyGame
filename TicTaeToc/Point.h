#pragma once
#include <iostream>
class Point final
{
public:
	Point(float x, float y);
	~Point();
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	const float GetX() const { return _x; };
	const float GetY() const { return _y; };
private:
	float _x, _y;
};
