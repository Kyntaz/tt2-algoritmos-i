#include <iostream>

int main() {
    unsigned int a, l, c;
    std::cin >> a >> l >> c;

    auto vol = a * l * c;
    auto check = vol > 50 && a > 3;
    std::cout << check;
    return 0;
}
