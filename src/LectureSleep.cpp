#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> theorems(n);
    std::vector<int> awake(n);
    for (auto& nTheo: theorems) {
        std::cin >> nTheo;
    }
    for (auto& isAwake: awake) {
        std::cin >> isAwake;
    }

    int baseTotal = 0;
    std::vector<int> cumulativeLost(n + 1);
    cumulativeLost[0] = 0;
    int sumLost = 0;
    for (int i = 0; i < n; i++) {
        baseTotal += awake[i] * theorems[i];

        int asleep = awake[i] ? 0 : 1;
        sumLost += asleep * theorems[i];
        cumulativeLost[i + 1] = sumLost; 
    }

    int bestGain = 0;
    for (int i = 1; i < n - k; i++) {
        int gain = cumulativeLost[i + k] - cumulativeLost[i - 1];
        bestGain = std::max(bestGain, gain);
    }

    std::cout << baseTotal + bestGain << std::endl;
    return 0;
}
