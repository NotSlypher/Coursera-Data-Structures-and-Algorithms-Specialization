#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous%m + current%m)%m;
    }

    return current % m;
}

long long get_pisano_period2(long long m) {

    long long a, b, c = 0;
    a = 0;
    b = 1;

    for (long long i = 2; i <= m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;

        if (a == 0 && b == 1) {
            return i - 1;
        }
    }
}
long long get_fibonacci_huge2(long long n, long long m) {
    long long period = get_pisano_period2(m);

    int rem = n % period;
    std::vector<long long> arr(rem + 2);
    arr[0] = 0;
    arr[1] = 1;
    int i;
    for (i = 2; i <= rem; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % m;
    }
    return arr[rem];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge2(n, m) << '\n';
}
