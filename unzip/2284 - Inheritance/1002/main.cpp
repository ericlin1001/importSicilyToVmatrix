#include <iostream>
#include <cmath>
using namespace std;
class GeometricObject {
	public:
		GeometricObject(string color, bool filled) {
			this->color = color;
			this->filled = filled;
		}

		string getColor() {
			return color;
		}
		void setColor(string color) {
			this->color = color;
		}
		bool isFilled() {
			return filled;
		}
		void setFilled(bool filled) {
			this->filled = filled;
		}
		string toString() {
			return "Geometric object color " + color +
			       " filled " + ((filled) ? "true" : "false");
		}
	private:
		string color;
		bool filled;
};

class Triangle: public GeometricObject {
	private:
		double side1, side2, side3;
	public:
		Triangle(): side1(1.0), side2(1.0), side3(1.0), GeometricObject("blue", true)  {};
		Triangle(double s1, double s2, double s3, string s = "blue", bool b = true): side1(s1), side2(s2), side3(s3), GeometricObject(s,b) {};
		double getSide1() {
			return side1;
		}
		double getSide2() {
			return side2;
		}
		double getSide3() {
			return side3;
		}
		double getArea() {
			double p = (side1 + side2 + side3) / 2;
			double area;
			area = sqrt(p*(p-side1)*(p-side2)*(p-side3));
			return area;
		}
		double getPerimeter() {
			return side1 + side2 + side3;
		}
};

