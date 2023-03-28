#include <iostream>
#include <ostream>
using std::ostream;
using std::cout;

class Complex
{
	
	friend ostream& operator<<(ostream& print, const Complex& p);

public:
	Complex();
	Complex (double r,double i);
	void set_real(double);
	void set_imaginary(double);
	double get_real()const;
	double get_imaginary()const;
	Complex operator+(const Complex& other);
	Complex operator+=(const Complex& other);
	Complex operator*=(const Complex& other);
	Complex operator/=(const Complex&other);
	Complex operator-=(const Complex&other);
	Complex operator-(const Complex& other);
	Complex operator*(const Complex& other);
	Complex operator/(const Complex& other);
	friend Complex operator*(double d, Complex& other);
	friend Complex operator*(Complex& other, double d);
	friend Complex operator/(Complex& other, double d);
	friend Complex operator/(double d, Complex& other);
	~Complex();
	














	


private:
	double d = 5.0;
	double real;
	double imaginary;

};

