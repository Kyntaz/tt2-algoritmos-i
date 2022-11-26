#include <iostream>
#include <algorithm>
#include <vector>

typedef long long number;

int main() {
    number n;
    std::cin >> n;

    number n;
    std::vector<number> v(n);
    for (number i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    number currSum = 0;
    number maxSum = v[0];
    for (number i = 0; i < n; i++) {
        currSum = std::max(currSum + v[i], v[i]);
        maxSum = std::max(currSum, maxSum);
    }

    std::cout << maxSum << std::endl;
    return 0;
}
