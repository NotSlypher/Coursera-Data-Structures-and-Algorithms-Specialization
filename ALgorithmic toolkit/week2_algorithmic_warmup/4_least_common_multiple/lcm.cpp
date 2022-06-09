#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_euclidean(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd_euclidean(b, a % b);
}

int main() {
  long long c, d, gcd, a, b;
  std::cin >> c >> d;
  a = c, b = d;
  gcd = gcd_euclidean(a, b);
  std::cout << c * d / gcd << std::endl;
  return 0;
}
