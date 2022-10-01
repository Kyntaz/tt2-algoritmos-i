#include <iostream>
#include <algorithm>

#define ABC abc[3]
#define A abc[0]
#define B abc[1]
#define C abc[2]

int main() {
    int n;
    int ABC;
    std::cin >> n >> A >> B >> C;
    std::sort(abc, abc + 3);

    for (int x = n / A; x >= 0; x--) {
        for (int y = (n - x*A) / B; y >= 0; y--) {
            for (int z = (n - x*A - y*B) / C; z >= 0; z--) {
                if (x*A + y*B + z*C == n) {
                    std::cout << x + y + z;
                    return 0;
                }
            }
        }
    }

    return 0;
}
