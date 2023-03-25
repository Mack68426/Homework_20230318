#include "shape.h"
#include <cmath>


/*-----------------------------*/
/*         rectangle           */
/*-----------------------------*/
rectangle::rectangle(float width, float height)
	:m_width(width), m_height(height)
{

}

float rectangle::width() const
{
	return m_width;
}
float rectangle::height() const 
{
	return m_height;
}

float rectangle::area() const
{
	return m_height * m_width;
}

float rectangle::perimeter() const
{
	return 2 * (m_width + m_height);
}

float rectangle::circumference() const
{
	return perimeter();
}

std::ostream& rectangle::shape_info(std::ostream& out) const
{
	return out  << "rectangle"
				<< "(w: " << width()  << ", "
				<< "h: " << height()  << ", "
				<< "area: " << area() << ", "
				<< "perimeter: " << perimeter() 
				<< ")";
}

std::string rectangle::shape_details() const
{
	return "rectangle(w: " + std::to_string(width())
		+  ", h: " + std::to_string(height())
		+  ", area: " + std::to_string(area())
		+  ", perimeter: " + std::to_string(perimeter())
		+  ")";
}

/*-----------------------------*/
/*            square           */
/*-----------------------------*/

square::square(float side)
	:rectangle(side, side)
{
}

float square::side() const
{
	return rectangle::width();
}

std::ostream& square::shape_info(std::ostream& out) const
{
	return out  << "square("
				<<"s: " << side()	  << ", "
				<< "area: " << area() << ", "
				<< "perimeter: " << perimeter()
				<< ")";
}

std::string square::shape_details() const
{
	return "square(s: " + std::to_string(side())
		+ ", area: " + std::to_string(area())
		+ ", perimeter: " + std::to_string(perimeter())
		+ ")";
}


/*-----------------------------*/
/*           circle            */
/*-----------------------------*/

circle::circle(float radius)
	:m_radius(radius)
{

}

float circle::radius() const
{
	return m_radius;
}

float circle::area() const
{
	return m_radius * m_radius * m_PI;
}

float circle::perimeter() const
{
	return circumference();
}


float circle::circumference() const
{
	return m_radius * m_PI * 2;
}

std::ostream& circle::shape_info(std::ostream& out) const
{
	return out  << "circle("
				<< "r: " << radius()	<< ", "
				<< "area: " << area()	<< ", "
				<< "circumference: " << circumference()
				<< ")";
}

std::string circle::shape_details() const
{
	return "circle(r: " + std::to_string(radius())
		+ ", area: " + std::to_string(area())
		+ ", circumference: " + std::to_string(circumference())
		+ ")";
}


/*-----------------------------*/
/*          triangle           */
/*-----------------------------*/

triangle::triangle(float bottom, float left_side, float right_side)
	:m_bottom(bottom), m_lside(left_side), m_rside(right_side)
{

}

float triangle::bottom() const
{
	return m_bottom;
}
float triangle::lside() const
{
	return m_lside;
}
float triangle::rside() const
{
	return m_rside;
}

float triangle::area() const
{
	float s = perimeter() / 2;
	return std::sqrt(s * (s - m_bottom) * (s - m_lside) * (s - m_rside));
}

float triangle::perimeter() const
{
	return m_bottom + m_lside + m_rside;
}

float triangle::circumference() const
{
	return perimeter();
}

std::ostream& triangle::shape_info(std::ostream& out) const
{
	return out  << "triangle("
				<< "b: " << bottom()	<< ", "
				<< "l: " << lside()		<< ", "
				<< "r: " << rside()		<< ", "
				<< "area: " << area()	<< ", "
				<< "perimeter: " << perimeter()
				<< ")";
}
std::string triangle::shape_details() const
{
	return "triangle(b: " + std::to_string(bottom())
		+ ", l: " + std::to_string(lside())
		+ ", r: " + std::to_string(rside())
		+ ", area: " + std::to_string(area())
		+ ", perimeter: " + std::to_string(perimeter())
		+ ")";
}



std::ostream& operator<<(std::ostream& os, const shape& sp)
{
	return sp.shape_info(os);
	// return os << sp.shape_details();
}

/*
std::ostream& operator<<(std::ostream& os, const rectangle& rect)
{
	return os << rect.shape_details();

}
std::ostream& operator<<(std::ostream& os, const square& sq)
{
	return os << sq.shape_details();
}
std::ostream& operator<<(std::ostream& os, const circle& cir)
{
	return os << cir.shape_details();
}
std::ostream& operator<<(std::ostream& os, const triangle& tri)
{
	return os << tri.shape_details();
}
*/