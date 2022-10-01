#include <iostream>

struct DragonKnights {
    int n;
    int m;
    int* ds;
    int* as;
};

DragonKnights readProblem() {
    int n, m;
    std::cin >> n >> m;

    auto ds = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        std::cin >> ds[i];
    }

    auto as = (int*) malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        std::cin >> as[i];
    }

    return { n, m, ds, as };
}

void freeDragonKnights(DragonKnights dk) {
    free(dk.ds);
    free(dk.as);
}

int solve(DragonKnights dk) {
    int money = 0;

    for (int i = 0; i < dk.n; i++) {
        bool found = false;
        for (int j = 0; j < dk.m; j++) {
            if (dk.as[j] >= dk.ds[i]) {
                money += dk.as[j];
                dk.as[j] = 0;
                found = true;
                break;
            }
        }

        if (!found) {
            return -1;
        }
    }

    return money;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        auto dk = readProblem();
        std::cout << solve(dk) << std::endl;
        freeDragonKnights(dk);
    }

    return 0;
}
