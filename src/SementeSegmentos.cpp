#include <iostream>
#include <numeric>

int main() {
    int n, q;
    std::cin >> n >> q;

    auto segments = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        std::cin >> segments[i];
    }

    for (int i = 0; i < q; i++) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int x, f;
            std::cin >> x >> f;
            segments[x - 1] = f;
        } else {
            int x, y;
            std::cin >> x >> y;
            auto ans = std::accumulate(segments + x - 1, segments + y, 0);
            std::cout << ans << std::endl;
        }
    }

    free(segments);
    return 0;
}
