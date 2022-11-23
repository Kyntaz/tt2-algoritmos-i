#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> deltas(n + 1, 0);
    while (k--) {
        int a, b;
        std::cin >> a >> b;
        deltas[a - 1]++;
        deltas[b]--;
    }

    int max = 0;
    int curr = 0;
    for (const auto delta: deltas) {
        curr += delta;
        max = max > curr ? max : curr;
    }

    std::cout << max << std::endl;
    return 0;
}
