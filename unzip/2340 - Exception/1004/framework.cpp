#include <iostream>
#include <stdexcept>
using namespace std;

int calc(int a, int b)
{
  if (a<0) throw out_of_range("Out of range exeception");
  else if (b<0) throw out_of_range("Out of range exeception");
  else if (a<b) throw logic_error("Minuend smaller than subtrahend");
  return a-b;
}

#include "source.cpp"


int main()
{
  
  test(3,1);
  test(-3,1);
  test(1,-3);
  test(1,3);
  return 0;
}
