#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int k = (-1 + sqrt(1 + 8 * n)) / 2, sum = 0;
  for (int i = 1; i < k; ++i)
  {
	  summands.push_back(i);
	  sum += i;
  }
  summands.push_back(n - sum);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
