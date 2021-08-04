/*
 * main.cpp
 *
 *  Created on: 4 авг. 2021 г.
 *      Author: pavel
 */
#include <iostream>
#include <cmath>
#include <cstdint>


class Power
{
private:
	float m_basis = 1.0;									// основание степени
	float m_exponent = 1.0;									// показатель степени

public:
	void set(float _basis, float _exponent)
	{
		m_basis = _basis;
		m_exponent = _exponent;
	}
	void calculate()
	{
		std::cout << "Number A to power B = " << pow(m_basis, m_exponent) << std::endl;
	}

};


class RGBA
{
private:
    std::uint8_t m_red   = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue  = 0;
    std::uint8_t m_alpha = 255;

public:
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : m_red(r), m_green(g), m_blue(b), m_alpha(a)
    {
    }

    RGBA()
    {
    }

    void print()
    {
        std::cout << "Red:   " << +m_red   << std::endl;
        std::cout << "Green: " << +m_green << std::endl;
        std::cout << "Blue:  " << +m_blue  << std::endl;
        std::cout << "Alpha: " << +m_alpha << std::endl;
    }
};



int main ()
{
 /*----------------  task 1 ------------------------------------*/

	Power varOne;
	Power varTwo;

	float a,b;

	std::cout << "Enter a (basis) and b (exponent): ";
	std::cin >> a >> b;
	varOne.set(a, b);
	std::cout << std::endl <<"custom data method:\n";
	varOne.calculate();
	std::cout << std::endl << "method with default values:\n";
	varTwo.calculate();

/* ----------------  task 2 ------------------------------------*/


    RGBA colorTwo;
    std::uint8_t red = 5, green =5 , blue=5, alpha=100;
    RGBA colorOne(red,green, blue, alpha);

    colorOne.print();
    std::cout << std::endl;
    colorTwo.print();






	return 0;

}
