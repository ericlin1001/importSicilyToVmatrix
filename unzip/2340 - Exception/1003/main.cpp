#include<iostream>
#include<cmath>
#include<exception>
#include<stdexcept>
#include<cstring>
using namespace std;

class EmptyStackException : public range_error {
	public:
		EmptyStackException(string s) : range_error(s) {
		}
};

class StackOfIntegers {
	public:
		StackOfIntegers() {
			num = 0;
		}
		bool empty() {
			return (!num);
		}
		int peek() {
			if (empty()) throw EmptyStackException("Empty Stack Exception");
			else return data[num - 1];
		}
		void push(int value) {
			data[num] = value;
			++num;
		}
		int pop() {
			if (empty()) throw EmptyStackException("Empty Stack Exception");
			else {
				int k = data[num - 1];
				--num;
				return k;
			}
		}
		int getSize() {
			return num;
		}
	private:
		int data[100];
		int num;
};

