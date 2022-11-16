#include <iostream>
#include <cstring>
#include <map>

void addChar(std::map<char, int>& cs, char c) {
    auto nc = cs.count(c) ? cs[c] : 0;
    cs[c] = nc + 1;
}

void addString(std::map<char, int>& cs) {
    char s[100];
    std::cin >> s;
    auto l = std::strlen(s);
    for (int i = 0; i < l; i++) {
        addChar(cs, s[i]);
    }
}

bool validateCs(std::map<char, int>& cs, int n) {
    for (auto pair = cs.begin(); pair != cs.end(); pair++) {
        if (pair->second % n != 0) {
            return false;
        }
    }
    return true;
}

bool solveProblem() {
    int n;
    auto cs = std::map<char, int>();
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        addString(cs);
    }

    return validateCs(cs, n);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        auto sol = solveProblem();
        std::cout << (sol ? "YES" : "NO") << std::endl;
    }

    return 0;
}
