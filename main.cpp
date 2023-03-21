#include <iostream>
#include <iomanip>
#include <string>
#include "shape.h"


int main(int argc, char* argv[])
{
	rectangle r{5, 3};
	square sq{ 10 };
	circle cir{ 1 };
	triangle tri{ 12, 13 , 5 };

	const shape& s = tri;
	const rectangle r2{ 2,3 };

	std::cout << s.area() << std::endl; // 30
	std::cout << s.circumference() << std::endl; // 30
	std::cout << s.perimeter() << std::endl; // 30

	/*********************************************************/
	// rectangle(w: XXX, h: XXX, area: XXX, perimeter: XXX)  //
	// square(s: XXX, area: XXX, perimeter: XXX)             //
	// circle(r: XXX, area: XXX, circumference: XXX)         //
	// triangle(?????, area: XXX, perimeter: XXX)            //
	/*********************************************************/

	std::cout << sq << std::endl; // square(s: 5, area: 25, perimeter: 20)
	std::cout << s << std::endl;

	return 0;
}