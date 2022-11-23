#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int sumBetween(std::vector<int>& cumulative, int i, int j) {
    return cumulative[j] - cumulative[i - 1];
}

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
    int i = 1;
    int j = n;
    while (j >= i) {
        max = std::max(max, sumBetween(cumulative, i, j));
        int nI = sumBetween(cumulative, i + 1, j);
        int nJ = sumBetween(cumulative, i, j - 1);
        if (nI > nJ) {
            i++;
        } else {
            j--;
        }
    }

    std::cout << max << std::endl;
    return 0;
}
