#include <iostream>
#include <cmath>

using namespace std;

class Point {
	private:
		double x,y;
	public:
		Point() {
			x = 0;
			y = 0;
		}
		Point(double xv,double yv) {
			x = xv;
			y = yv;
		}
		Point(Point& pt) {
			x = pt.getx();
			y = pt.gety();
		}
		double getx() {
			return x;
		}
		double gety() {
			return y;
		}
};

class Circle: public Point {
	private:
		double radius;
	public:
		Circle() {
			radius = 0;
		}
		Circle(double xv, double yv, double theRadius);
		Circle(Circle& cir);
		double getRadius() {
			return radius;
		}
		int position(Point& pt);
};

class Rectangle: public Point {
	private:
		double length;
		double width;
	public:
		Rectangle(double xv, double yv, double theLen, double theWid);
		Rectangle() {
			length = 0;
			width = 0;
		}
		Rectangle(Rectangle& rec);
		double getLen() {
			return length;
		}
		double getWid() {
			return width;
		}
		int position(Point& pt);
};

Circle::Circle(double xv, double yv, double theRadius):Point(xv, yv) {
	radius = theRadius;
}

Circle::Circle(Circle& cir):Point(cir) {
	radius = cir.getRadius();
}

int Circle::position(Point& pt) {
	double d = pow(pt.getx() - getx(),2) + pow(pt.gety() - gety(),2);
	double R = pow(getRadius(),2);
	if (d > R)
		return 1;
	else if (d == R)
		return 0;
	else
		return -1;
}

Rectangle::Rectangle(double xv, double yv, double theLen, double theWid):Point(xv, yv) {
	length = theLen;
	width = theWid;
}

Rectangle::Rectangle(Rectangle& rec):Point(rec) {
	length = rec.getLen();
	width = rec.getWid();
}

int Rectangle::position(Point& pt) {
	double dx = pt.getx() - getx();
	double dy = pt.gety() - gety();
	if (dx > 0 && dx < length && dy > 0 && dy < width)
		return -1;
	else if (((dx == 0 || dx == length) && dy >= 0 && dy <= width) ||((dy == 0 || dy == width) && dx >= 0 && dx <= length))
		return 0;
	else
		return 1;
}

