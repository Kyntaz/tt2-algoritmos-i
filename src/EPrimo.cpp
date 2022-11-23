#include <iostream>

typedef long long number;

bool ePrimo(number n) {
    for (number i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    number n;
    std::cin >> n;
    std::cout << (int) ePrimo(n) << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
