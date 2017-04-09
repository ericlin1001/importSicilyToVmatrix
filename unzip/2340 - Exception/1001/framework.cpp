#include "source.cpp"
#include <iostream>
#include <cstring>
using namespace std;

void f(const char* const binaryString)
{
  try
  {
    cout << parseBinary(binaryString) << endl;
  }
  catch(runtime_error ex)
  {
    cout << ex.what() << endl;
  }
}

int main()
{
    f("10001");
    f("11111111");
    f("10101010101010");
    f("111511");
    f("111111111111");
    return 0;
}

