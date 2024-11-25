#include <iostream>
#include <unordered_map>
#include <vector>

const int MOD = 1e9 + 7;

// Function to find Pisano period for modulus m
std::vector<int> pisanoPeriod(int m) {
    std::vector<int> period;
    int previous = 0, current = 1;
    period.push_back(previous);
    period.push_back(current);

    for (int i = 0; i < m * m; i++) {
        int temp = current;
        current = (previous + current) % m;
        previous = temp;

        // The period starts with 0, 1
        if (previous == 0 && current == 1) {
            break;
        }
        period.push_back(current);
    }

    return period;
}

// Function to find G(n, k)
int G(long long n, int k) {
    std::vector<int> period = pisanoPeriod(k);
    int period_length = period.size();
    std::vector<int> divisible_indices;

    // Collect indices of Fibonacci numbers divisible by k
    for (int i = 0; i < period_length; i++) {
        if (period[i] % k == 0) {
            divisible_indices.push_back(i + 1);  // +1 for 1-based index
        }
    }

    // Number of divisible Fibonacci numbers in one period
    int m = divisible_indices.size();

    if (m == 0) return -1;  // If no Fibonacci number is divisible by k

    // The total full periods we can have
    long long full_periods = n / m;
    long long total_count = full_periods * period_length + (n % m);

    // Get the G(n, k) value
    return divisible_indices[total_count % m] % MOD;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        int k;
        std::cin >> n >> k;

        int result = G(n, k);
        std::cout << result << std::endl;
    }

    return 0;
}
