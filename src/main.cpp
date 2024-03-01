#include <Converter.h>
#include <iostream>

int
main()
{
// ToDo
#if DEPRECATED
  Point a{ 1., 2. };
  Point b{ 10., 0. };
  Point c{ 9., 9. };
  Point d{ 2., 8. };
  Point k{ 3.12, 3.18 };
#else // DEPRECATED
  Point a{ 2, 2 };
  Point b{ 11, 1 };
  Point c{ 13, 12 };
  Point d{ 3, 10 };
  Point k{ 7, 5 };
#endif // DEPRECATED
  auto res = Converter::CulculateP(a, b, c, d, k);
  std::cout << "x = " << std::get<0>(res) << " | y = " << std::get<1>(res) << std::endl;

  return 0;
}