#include <iostream>

unsigned long guimaracci(int n, unsigned long* memo) {
    if (memo[n] > 0) {
        return memo[n];
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 3;
    } else {
        memo[n] = guimaracci(n - 1, memo) + guimaracci(n - 2, memo);
        return memo[n];
    }
}

unsigned long guimaracci(int n) {
    auto memo = (unsigned long*) calloc(n, sizeof(long));
    auto result = guimaracci(n, memo);
    free(memo);
    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << guimaracci(n);
    
    return 0;
}
