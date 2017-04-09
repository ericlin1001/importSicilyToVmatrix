#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T, int capacity>
class Stack
{
public:
	Stack();            // Constructs an empty stack.
	bool empty();       // Returns true if the stack is empty.
	T peek();           // Returns the element at the top of the stack without removing it from the stack.
	void push(T value); // Stores an element into the top of the stack.
	T pop();            // Removes the element at the top of the stack and returns it.
	int size();         // Returns the number of elements in the stack.
private:
	T* elements;        // Points to an array that stores elements in the stack.
	int num;            // The number of the elements in the stack.
};

#include "source.cpp"

int main()
{
	//freopen("test01.in", "r", stdin);
	//freopen("test01.out", "w", stdout);

	Stack<int,15> intStack;
	for (int i = 0; i < 15; i++) intStack.push(i);

	cout<<intStack.size()<<endl;
	while (!intStack.empty()) {
		cout << intStack.peek() << " ";
		intStack.pop();
	}
	cout << endl;

	Stack<string,3> stringStack;
	stringStack.push("Chicago");
	stringStack.push("Denver");
	stringStack.push("London");

	while (!stringStack.empty())
		cout << stringStack.pop() << " ";
	cout << endl;

	return 0;
}