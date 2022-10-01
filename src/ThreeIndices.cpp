#include <iostream>

struct CountedIntArray {
    int* ns;
    size_t l;
};

struct Answer {
    int i;
    int j;
    int k;
};

CountedIntArray readProblem() {
    size_t l;
    std::cin >> l;
    auto ns = (int*) malloc(sizeof(int) * l);

    for (int i = 0; i < l; i++) {
        std::cin >> ns[i];
    }

    return { ns, l };
}

int findSmaller(int from, int to, int thresh, int* ns) {
    for (int i = from; i < to; i++) {
        if (ns[i] < thresh) {
            return i;
        }
    }
    return -1;
}

Answer solveProblem() {
    Answer ans = { -1, -1, -1 };
    auto problem = readProblem();

    for (int j = 1; j < problem.l - 1; j++) {
        int i = findSmaller(0, j, problem.ns[j], problem.ns);
        if (i < 0) {
            continue;
        }

        int k = findSmaller(j + 1, problem.l, problem.ns[j], problem.ns);
        if (k < 0) {
            continue;
        }

        ans = { i, j, k };
        break;
    }

    free(problem.ns);
    return ans;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        auto answer = solveProblem();
        if (answer.i < 0) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
            std::cout << answer.i + 1 << " " << answer.j + 1 << " " << answer.k + 1 << std::endl;
        }
    }

    return 0;
}
