#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max1 = 0, max2 = 0, max = -1;
    long long n = numbers.size();

    for (long long first = 0; first < n; ++first) {
        if (numbers[first] > numbers[max1]) {
            max1 = first;
            max = numbers[first];
        }
    }
    max = -1;
    for (long long first = 0; first < n; ++first) {
        if (numbers[first] > max && first != max1) {
            max2 = first;
            max = numbers[first];
        }
    }

    return numbers[max1]*numbers[max2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
