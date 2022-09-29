#include <iostream>

int main() {
    unsigned int n;
    int k;
    std::cin >> n >> k;

    for (unsigned int i = 0; i < n; i++) {
        int ni;
        std::cin >> ni;

        if (ni >= k) {
            std::cout << ni << " ";
        }
    }

    return 0;
}
