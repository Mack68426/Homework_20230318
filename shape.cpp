#include "shape.h"
#include <math.h>
#include <string>
#include <sstream>
#include <ostream>


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

void rectangle::shape_info(std::ostream& out) const
{
	out << "rectangle(w: " << width()
		<< "(h: " << height()
		<< ", area: " << area()
		<< ", perimeter: " << perimeter()
		<< ")";
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

void square::shape_info(std::ostream& out) const
{
	out << "square(s: " << side()
		<< ", area: " << area()
		<< ", perimeter: " << perimeter()
		<< ")";
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

void circle::shape_info(std::ostream& out) const
{
	out << "circle(r: " << radius()
		<< ", area: " << area()
		<< ", circumference: " << circumference()
		<< ")";
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

void triangle::shape_info(std::ostream& out) const
{
	out << "triangle(b: " << bottom()
		<< ", l: " << lside()
		<< ", r: " << rside()
		<< ", area: " << area()
		<< ", perimeter: " << perimeter()
		<< ")";
}




std::ostream& operator<<(std::ostream& os, const shape& sp)
{	
	// return os << "it won't print anything (._.)";
	sp.shape_info(os);
	return os;
}


std::ostream& operator<<(std::ostream& os, const rectangle& rect)
{
	rect.shape_info(os);

	return os;
}
std::ostream& operator<<(std::ostream& os, const square& sq)
{
	sq.shape_info(os);

	return os;
}
std::ostream& operator<<(std::ostream& os, const circle& cir)
{
	cir.shape_info(os);

	return os;

}
std::ostream& operator<<(std::ostream& os, const triangle& tri)
{
	tri.shape_info(os);

	return os;
}
