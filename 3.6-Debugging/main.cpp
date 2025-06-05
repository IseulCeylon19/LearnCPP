#include <iostream>

void a()
{
	std::cout << "a() called\n";
}

void b()
{
	std::cout << "b() called\n";
	a();
}

void printValue(int value)
{
  std::cout << "Value: " << value << std::endl;
}

int main()
{

#ifdef DEBUG
  std::cout << "Debugging mode is enabled." << std::endl;
  std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)
#endif

	int x{ 1 };
	std::cout << x << ' ';

	x = x + 2;
	std::cout << x << ' ';

	x = x + 3;
	std::cout << x << ' ';

  a();
  b();
  
  printValue(x);

  return 0;
}
