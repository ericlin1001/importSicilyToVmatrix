#include <iostream>
#include "source.cpp"
using namespace std;

void f1()
{
  StackOfIntegers s;

  cout << s.getSize() << endl;
  for (int i = 0; i < 10; i++)
  {  
    s.push(i);
    cout << s.getSize() << " " << s.peek() << endl;
  }
  while (!s.empty())
    cout << s.pop() << " ";
  cout << endl;
}

void f2()
{
  StackOfIntegers s;

  try
  {
    s.peek();
  }
  catch(EmptyStackException ex)
  {
    cout << "Empty Stack Exception" << endl;
  }
  
  try
  {
    s.pop();
  }
  catch(EmptyStackException ex)
  {
    cout << "Empty Stack Exception" << endl;
  }
}

int main()
{
  f2();
  f1();
  return 0;
}
