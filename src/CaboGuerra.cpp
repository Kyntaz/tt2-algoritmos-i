#include <iostream>

int main() {
    unsigned int n;
    std::cin >> n;

    unsigned int a = 0, b = 0;
    for (unsigned int i = 0; i < n; i++) {
        int f;
        std::cin >> f;

        if (i % 2 == 0) {
            a += f;
        } else {
            b += f;
        }
    }

    if (a > b) {
        std::cout << "A";
    } else if (a < b) {
        std::cout << "B";
    } else {
        std::cout << "E";
    }
    
    return 0;
}
