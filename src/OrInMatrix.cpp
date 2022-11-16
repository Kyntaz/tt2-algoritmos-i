#include <iostream>
#include <cstring>

class Matrix {
    private:
    int* grid = nullptr;

    size_t getDataSize() {
        return sizeof(int) * m * n;
    }

    void allocateData() {
        freeData();
        grid = (int*) malloc(getDataSize());
    }

    public:
    int m = 0, n = 0;

    int at(int i, int j) {
        return grid[i * n + j];
    }

    void set(int i, int j, int c) {
        grid[i * n + j] = c;
    }

    void read() {
        std::cin >> m >> n;
        allocateData();

        for (int i = 0; i < m * n; i++) {
            std::cin >> grid[i];
        }
    }

    void init(int val, int im, int in) {
        m = im;
        n = in;
        allocateData();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                set(i, j, val);
            }
        }
    }

    void write() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << at(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void freeData() {
        if (grid != nullptr) {
            free(grid);
        }
    }
};

void setLinColZeros(Matrix& m, int i, int j) {
    for (int c = 0; c < m.m; c++) {
        m.set(c, j, 0);
    }
    
    for (int c = 0; c < m.n; c++) {
        m.set(i, c, 0);
    }
}

void findZeros(Matrix& a, Matrix& b) {
    for (int i = 0; i < b.m; i++) {
        for (int j = 0; j < b.n; j++) {
            if (b.at(i, j) == 0) {
                setLinColZeros(a, i, j);
            }
        }
    }
}

bool hasLinColOne(Matrix& m, int i, int j) {
    for (int c = 0; c < m.m; c++) {
        if (m.at(c, j) == 1) {
            return true;
        }
    }
    
    for (int c = 0; c < m.n; c++) {
        if (m.at(i, c) == 1) {
            return true;
        }
    }

    return false;
}

bool checkOnes(Matrix& a, Matrix& b) {
    for (int i = 0; i < b.m; i++) {
        for (int j = 0; j < b.n; j++) {
            if (b.at(i, j) == 1 && !hasLinColOne(a, i, j)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    Matrix a, b;

    b.read();
    a.init(1, b.m, b.n);

    
    findZeros(a, b);
    if (checkOnes(a, b)) {
        std::cout << "YES" << std::endl;
        a.write();
    } else {
        std::cout << "NO" << std::endl;
    }

    a.freeData();
    b.freeData();
    return 0;
}
