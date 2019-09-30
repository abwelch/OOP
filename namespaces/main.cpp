#include "car.hpp"
#include "motorcycle.hpp"
#include <iostream>

int main()
{
	car::Engine a;
	motorcycle::Engine b;
	std::cout << a.get_hp() << std::endl;
	std::cout << b.get_hp() << std::endl;
	return 0;
}