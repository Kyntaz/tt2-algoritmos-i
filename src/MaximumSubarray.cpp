#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cumulative(n + 1);
    cumulative[0] = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int curr;
        std::cin >> curr;
        sum += curr;
        cumulative[i+1] = sum;
    }

    int max = INT_MIN;
    for (int i = 1; i < cumulative.size(); i++) {
        for (int j = 1; j <= i; j++) {
            int subtotal = cumulative[i] - cumulative[j - 1];
            max = std::max(max, subtotal);
        }
    }

    std::cout << max << std::endl;
    return 0;
}
