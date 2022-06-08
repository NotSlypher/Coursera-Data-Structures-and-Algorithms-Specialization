#include <iostream>
#include <vector>
#define ll long long
long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    std::vector<ll> a(n);
    for (long long i = 0; i < n; ++i)
    {
        if (i < 2)
        {
            a[0] = 1ll;
            a[1] = 1ll;
        }
        else
        {
            a[i] = (a[i - 1ll] + a[i - 2ll]) % m;
        }
    }
    return a[n - 1ll] % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
