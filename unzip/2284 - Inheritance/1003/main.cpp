#include <iostream>
class Point {
		int x,y;
	public:
		Point(int x,int y) {
			this->x = x;
			this->y = y;
		}
		void Move(int x,int y) {
			this->x += x;
			this->y += y;
		}
		int Getx() {
			return x;
		};
		int Gety() {
			return y;
		};
};

class Rectangle: public Point {
	private:
		double length, width;
	public:
		Rectangle(int a, int b, double l, double w): Point(a, b), length(l), width(w) {};
		double Getlength() {
			return length;
		}
		double Getwidth() {
			return width;
		}
		double Getarea() {
			return length * width;
		}
};

