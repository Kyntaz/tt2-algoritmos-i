#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
    unsigned int ss[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> ss[i];
    }
    
    std::sort(ss, ss + 3);
    auto dHyp = sqrt(pow(ss[0], 2) + pow(ss[1], 2)) - ss[2];

    if (dHyp < 0) {
        std::cout << "Obtuso";
    } else if (dHyp == 0) {
        std::cout << "Rectangulo";
    } else {
        std::cout << "Agudo";
    }

    return 0;
}
