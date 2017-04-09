#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Stack {
	public:
		Stack() {
			top = 0;
		};
		~Stack() {
			node *p;
			if(top!=0) {
				p = top;
				top = top->link;
				delete p;
			}
		};
		bool empty() {
			if(top == 0) return true;
			else return false;
		};
		T peek() {
			return top->element;
		};
		void push(T value) {
			node *p;
			p = new node;
			p->link = top;
			p->element = value;
			top = p;
		};
		T pop() {
			node *p;
			p = top;
			top = top->link;
			delete p;
		};
		int getSize() {
		};
		void printStack() {
			node *p;
			p = top;
			while(p!=0) {
				cout<<p->element<<endl;
				p = p->link;
			}
		};
	private:
		struct node {
			T element;
			node *link;
		};
		node *top;
};

