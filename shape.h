#pragma once

#include <string>
#include <ostream>

class shape
{
public:
	/*   copy constructor:   */
	/* shape(cosnt shape&);  */

	// undefined behavior UB
	// virtual destructor
	virtual ~shape() = default;

	// abstruct
	virtual float area() const = 0; // pure virtual method
	virtual float perimeter() const = 0;
	virtual float circumference() const = 0;
	virtual std::ostream& shape_info(std::ostream&) const = 0;
	virtual std::string shape_details() const = 0;
};


// concrete
class rectangle : public shape
{
public:

	rectangle() = default;
	rectangle(float width, float height);

	float width() const;
	float height() const;
	float area() const override;
	float perimeter() const override;
	float circumference() const override;

	std::ostream& shape_info(std::ostream&) const override;

	std::string shape_details() const override;

private:
	float m_width;
	float m_height;
};



class square : public rectangle
{
public:
	square(float side);

	float side() const;
	std::ostream& shape_info(std::ostream&) const override;

	std::string shape_details() const override;
};



class circle : public shape
{
public:
	circle() = default;
	circle(float radius);

	float radius() const;
	float area() const override;
	float perimeter() const override;
	float circumference() const override;
	std::ostream& shape_info(std::ostream&) const override;

	std::string shape_details() const override;

private:
	const float m_PI = 3.1415926F;
 	float m_radius;
};


// undone
class triangle : public shape
{
public:
	triangle() = default;
	triangle(float bottom, float left_side, float right_side);

	float bottom() const;
	float lside() const;
	float rside() const;


	float area() const override;
	float perimeter() const override;
	float circumference() const override;
	std::ostream& shape_info(std::ostream&) const override;

	std::string shape_details() const override;

private:
	float m_bottom;
	float m_lside;
	float m_rside;
};

std::ostream& operator<<(std::ostream& os, const shape& sp);

/*
std::ostream& operator<<(std::ostream& os, const rectangle& rect);
std::ostream& operator<<(std::ostream& os, const square& sq);
std::ostream& operator<<(std::ostream& os, const circle& cir);
std::ostream& operator<<(std::ostream& os, const triangle& tri);
*/