#include <iostream>
#include <algorithm>

int main() {
    unsigned int hs[3];
    std::cin >> hs[0] >> hs[1] >> hs[2];

    std::sort(hs, hs + 3);
    for (auto i : hs) {
        std::cout << i << " ";
    }
    
    return 0;
}
