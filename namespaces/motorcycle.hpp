#pragma once

namespace motorcycle
{


class Engine
{
private:
	int horsepower = 100;
public:
	Engine();
	int get_hp() 
	{
		return horsepower;
	}

};

class Wheel
{


};

}