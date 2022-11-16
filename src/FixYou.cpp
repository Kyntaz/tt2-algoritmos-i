#include <iostream>

class Belt {
    private:
    char* grid = nullptr;

    public:
    int nLin = 0, nCol = 0;
    
    char at(int l, int c) {
        if (l < nLin && c < nCol) {
            return grid[l * nCol + c];
        } else {
            return 'O';
        }
    }

    void read() {
        freeGrid();
        std::cin >> nLin >> nCol;
        grid = (char*) malloc(sizeof(char) * nLin * nCol);
        
        for (int i = 0; i < nLin; i++) {
            std::cin >> (grid + i * nCol);
        }
    }

    void freeGrid() {
        if (grid != nullptr) {
            free(grid);
        }
    }
};

int solveProblem(Belt& belt) {
    int n = 0;
    belt.read();

    for (int l = 0; l < belt.nLin - 1; l++) {
        if (belt.at(l, belt.nCol - 1) != 'D') {
            n++;
        }
    }

    for (int c = 0; c < belt.nCol - 1; c++) {
        if (belt.at(belt.nLin - 1, c) != 'R') {
            n++;
        }
    }

    return n;
}

int main() {
    Belt belt;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << solveProblem(belt) << std::endl;
    }

    belt.freeGrid();
    return 0;
}
