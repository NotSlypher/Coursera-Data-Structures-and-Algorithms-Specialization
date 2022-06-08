#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
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
            a[i] = (a[i - 1ll] + a[i - 2ll]) % 10;
        }
    }
    return a[n - 1ll] % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
