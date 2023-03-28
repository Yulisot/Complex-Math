#include "Complex.h"
using std::endl;


Complex::Complex()
{
	real = 0;
	imaginary = 0;
}

Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}

void Complex::set_real(double r)
{
	real = r;
}

void Complex::set_imaginary(double i)
{
	imaginary = i;
}

double Complex::get_real() const
{
	return real;
}

double Complex::get_imaginary() const
{
	return imaginary;
}

Complex Complex::operator+(const Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(this->get_real() + other.get_real());
	tmp->set_imaginary(this->get_imaginary() + other.get_imaginary());
	return *tmp;
}

Complex Complex::operator+=(const Complex& other)
{
	Complex* tmp = new Complex;
	this->set_real(this->get_real() + other.get_real());
	this->set_imaginary(this->get_imaginary() + other.get_imaginary());
	return *tmp;
	
}

Complex Complex::operator*=(const Complex& other) 
{
	double real_part = this->get_real() * other.get_real() - this->get_imaginary() * other.get_imaginary();
	double imaginary_part = this->get_real() * other.get_imaginary() + this->get_imaginary() * other.get_real();
	this->set_real(real_part);
	this->set_imaginary(imaginary_part);
	return *this;

	
}

Complex Complex::operator/=(const Complex& other) 
{
	double real_numerator = this->get_real() * other.get_real() + this->get_imaginary() * other.get_imaginary();
	double real_denominator = other.get_real() * other.get_real() + other.get_imaginary() * other.get_imaginary();
	double imaginary_numerator = this->get_imaginary() * other.get_real() - this->get_real() * other.get_imaginary();
	double imaginary_denominator = real_denominator;
	this->set_real(real_numerator / real_denominator);
	this->set_imaginary(imaginary_numerator / imaginary_denominator);
	return *this;
}

Complex Complex::operator-=(const Complex& other)
{
	Complex* tmp = new Complex;
	this->set_real(this->get_real() - other.get_real());
	this->set_imaginary(this->get_imaginary() - other.get_imaginary());
	return *tmp;

}

Complex Complex::operator-(const Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(this->get_real() - other.get_real());
	tmp->set_imaginary(this->get_imaginary() - other.get_imaginary());
	return *tmp;


}

Complex Complex::operator*(const Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real((this->get_real() * other.get_real()) - (this->get_imaginary() * other.get_imaginary()));
	tmp->set_imaginary((this->get_real() * other.get_imaginary()) + ((this->get_imaginary() * other.get_real())));
	return *tmp;
}

Complex Complex::operator/(const Complex& other)
{

	double r = (real * other.real + imaginary * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
	double i = (imaginary * other.real - real * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
	return Complex(r, i);
}



ostream& operator<<(ostream& print, const Complex& p)
{
	
	if (p.get_imaginary() == 0)
	{
		print << p.get_real();
	}
	if (p.get_imaginary() > 0)
	{
		print << p.get_real() << "+" << p.get_imaginary() << "i";
		return print;
	}
	if (p.get_imaginary() < 0)
	{
		print << p.get_real() << " " << p.get_imaginary() << "i";
		return print;
	}
}

Complex operator*(double d, Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() * d);
	tmp->set_imaginary(other.get_imaginary()*d);
	return *tmp;
}

Complex operator*(Complex& other, double d)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() * d);
	tmp->set_imaginary(other.get_imaginary()*d);
	return *tmp;
}

Complex operator/(Complex& other, double d)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() / d);
	tmp->set_imaginary(other.get_imaginary() / d);
	return *tmp;
}

Complex operator/(double d, Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() / d);
	tmp->set_imaginary(other.get_imaginary() / d);
	return *tmp;
}

Complex::~Complex()
{
	cout << "(-0-)" << endl;
}

