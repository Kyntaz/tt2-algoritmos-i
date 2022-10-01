#include <iostream>
#include <numeric>

struct Problem {
    int k;
    int n;
    int* as;
};

struct IndexTotalHeight {
    int i;
    int sh;
};

Problem readProblem() {
    int k, n;
    std::cin >> n >> k;
    
    auto as = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        std::cin >> as[i];
    }

    return { k, n, as };
}

IndexTotalHeight findBestSet(Problem problem) {
    int i = 0;
    int sh = 0;
    for (int j = 0; j < problem.n; j++) {
        int csh = std::accumulate(problem.as + j, problem.as + j + problem.k, 0);
        if (csh > sh) {
            sh = csh;
            i = j;
        }
    }

    if (sh == 0) {
        return { -1, 0 };
    } else {
        return { i, sh };
    }
}

void removeSet(Problem problem, int i) {
    for (int j = i; j < i + problem.k; j++) {
        problem.as[j] = 0;
    }
}

int main() {
    auto problem = readProblem();

    int sh = 0;
    for (int i = 0; i < 3; i++) {
        auto bestSet = findBestSet(problem);
        sh += bestSet.sh;
        if (bestSet.i >= 0) {
            removeSet(problem, bestSet.i);
        }
    }

    free(problem.as);

    std::cout << sh;
    return 0;
}
