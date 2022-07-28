#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = (int)a.size() - 1, m;
    //write your code here
    while (left <= right)
    {
        m = (left + right) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] < x)
            left = m + 1;
        else
            right = m - 1;
    }
    return -1;
}

int first_occ(const vector<int> &a, int x)
{
    int l = binary_search(a, x);
    if (l != -1) {
        for (int i = l; i >= 0 && a[i] == x; --i) {
            l = i;
        }
    }
    return l;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << first_occ(a, b[i]) << ' ';
  }
}
