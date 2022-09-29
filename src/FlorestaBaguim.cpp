#include <iostream>

int main() {
    unsigned int n, k;
    std::cin >> n >> k;

    bool success = false;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int c = 0;
        for (unsigned int j = 0; j < n; j++) {
            char p;
            std::cin >> p;
            
            if (!success) {
                if (p == '#') {
                    c = 0;
                } else {
                    c++;
                }

                if (c >= k) {
                    success = true;
                }
            }
        }
    }

    std::cout << success;
    return 0;
}
