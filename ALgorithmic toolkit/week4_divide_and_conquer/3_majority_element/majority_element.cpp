#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
    right = right - 1;
    int m;
    if (a[(left + right) / 2] == a[left])
        return 1;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
