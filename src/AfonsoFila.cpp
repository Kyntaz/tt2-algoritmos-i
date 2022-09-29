#include <iostream>

int main() {
    unsigned int n;
    std::cin >> n;

    unsigned int max = 0;
    unsigned int count = 0;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int h;
        std::cin >> h;

        if (h > max) {
            max = h;
            count++;
        }
    } 

    std::cout << count;
    return 0;
}
