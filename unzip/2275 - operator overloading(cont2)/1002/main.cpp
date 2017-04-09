#include <iostream>
#include <stdio.h>
using namespace std;

class Complex {
		double re; //real part of a complex number
		double im; //imaginary part of a complex number
	public:
		Complex() {
			re = 0;
			im = 0;
		}
		Complex(double a,double b = 0) {
			re = a;
			im = b;
		}
		Complex(const Complex& B) {
			re = B.re;
			im = B.im;
		}
		double real() const {
			return re;
		}
		double imag() const {
			return im;
		}
		friend ostream &operator<<(ostream &os,const Complex &c) {
			os << "(" << c.re << "," << c.im << ")";
			return os;
		}
		friend istream &operator>>(istream &is,Complex &c) {
			char i;
			is >> i >> c.re >> i >> c.im >> i;
			return is;
		}
		Complex operator+(const Complex& B) {
			Complex temp;
			temp.re = re + B.re;
			temp.im = im + B.im;
			return temp;
		}
		Complex& operator+=(const Complex& B) {
			re += B.re;
			im += B.im;
			return *this;
		}
		Complex operator+(double num) {
			Complex temp;
			temp.re = re + num;
			temp.im = im;
			return temp;
		}
		friend Complex operator+(double num,const Complex & B) {
			Complex temp;
			temp.re = B.re + num;
			temp.im = B.im;
			return temp;
		}
		Complex operator-(const Complex& B) {
			Complex temp;
			temp.re = re - B.re;
			temp.im = im - B.im;
			return temp;
		}
		Complex operator-(double num) {
			Complex temp;
			temp.re = re - num;
			temp.im = im;
			return temp;
		}
		friend Complex operator-(double num,const Complex & B) {
			Complex temp;
			temp.re = num - B.re;
			temp.im = -B.im;
			return temp;
		}
		Complex& operator-=(const Complex& B) {
			re -= B.re;
			im -= B.im;
			return *this;
		}
		Complex operator*(const Complex& B) {
			Complex temp;
			temp.re = re * B.re - im * B.im;
			temp.im = im * B.re + re * B.im;
			return temp;
		}
		Complex operator*(double num) {
			Complex temp;
			temp.re = re * num;
			temp.im = im * num;
			return temp;
		}
		friend Complex operator*(double num,const Complex & B) {
			Complex temp;
			temp.re = num * B.re;
			temp.im = B.im * num;
			return temp;
		}
		Complex& operator*=(const Complex& B) {
			double temp1 = re, temp2 = im;
			re = temp1 * B.real() - temp2 * B.imag();
			im = temp1 * B.imag() + temp2 * B.real();
			return *this;
		}
		Complex operator/(const Complex& B) {
			Complex temp;
			temp.re = (re * B.re + im * B.im) / (B.re * B.re + B.im * B.im);
			temp.im = (im * B.re - re * B.im) / (B.re * B.re + B.im * B.im);
			return temp;
		}
		Complex& operator/=(const Complex& B) {
			Complex temp;
			temp.re = (re * B.re + im * B.im) / (B.re * B.re + B.im * B.im);
			temp.im = (im * B.re - re * B.im) / (B.re * B.re + B.im * B.im);
			re = temp.re;
			im = temp.im;
			return *this;
		}
		Complex operator/(double num) {
			Complex temp;
			temp.re = re / num;
			temp.im = im / num;
			return temp;
		}
		friend Complex operator/(double num,const Complex & B) {
			Complex temp;
			temp.re = (num * B.re) / (B.re * B.re + B.im * B.im);
			temp.im = ((-num) * B.im) / (B.re * B.re + B.im * B.im);
			return temp;
		}
		bool operator == (const Complex& B) {
			if (re - B.re < 1e-10 && im - B.im < 1e-10) {
				return true;
			} else {
				return false;
			}
		}
		bool operator != (const Complex& B) {
			if (re - B.re < 1e-10 && im - B.im < 1e-10) {
				return false;
			} else {
				return true;
			}
		}
		bool operator == (double num) {
			if (re - num < 1e-10 && im - 0.0 < 1e-10) {
				return true;
			} else {
				return false;
			}
		}
		bool operator != (double num) {
			if (re - num < 1e-10 && im - 0.0 < 1e-10) {
				return false;
			} else {
				return true;
			}
		}
		friend bool operator == (double num, const Complex& B) {
			if (B.re - num < 1e-10 && B.im - 0.0 < 1e-10) {
				return true;
			} else {
				return false;
			}
		}
		friend bool operator != (double num, const Complex& B) {
			if (B.re == num && B.im == 0) {
				return false;
			} else {
				return true;
			}
		}
		Complex operator-() {
			Complex temp;
			temp.re = -re;
			temp.im = -im;
			return temp;
		}
};

