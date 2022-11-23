#include <iostream>
#include <vector>

int getSum(std::vector<int>& cumulative, int start, int end) {
    return cumulative[end] - cumulative[start - 1];
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> cumulative(n + 1);
    cumulative[0] = 0;
    int acc = 0;
    for (int i = 0; i < n; i++) {
        int p;
        std::cin >> p;
        acc += p;
        cumulative[i + 1] = acc;
    }

    int f;
    std::cin >> f;
    while (f--) {
        int start, end;
        std::cin >> start >> end;
        std::cout << getSum(cumulative, start, end) << std::endl;
    }

    return 0;
}
