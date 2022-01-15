#pragma once

#include <string.h>

/*
	This file holds all the class definitions.
*/


struct Point
{
private:
	double m_x_coord, m_y_coord;
	
public:
	Point(double x, double y) : 
		m_x_coord{ x },
		m_y_coord{ y } {}

	inline double GetX() { return m_x_coord; }
	
	inline double GetY() { return m_y_coord; }

	void PrintLocation()
	{
		printf("Point is (%f, %f)", m_x_coord, m_y_coord);
		std::cout << "\n";
	}
};

class Station
{



private:
	std::string m_name;

};