#include <iostream>

typedef unsigned long number;

void printLuckyNumber(number fours, number sevens) {
    for (number i = 0; i < fours; i++) {
        std::cout << '4';
    }

    for (number i = 0; i < sevens; i++) {
        std::cout << '7';
    }

    std::cout << std::endl;
}

int main() {
    number n;
    std::cin >> n;

    number maxFours = n / 4 + 1;
    number maxSevens = n / 7 + 1;

    for (number fours = 0; fours < maxFours; fours++) {
        for (number sevens = 0; sevens < maxSevens; sevens++) {
            if (fours * 4 + sevens * 7 == n) {
                printLuckyNumber(fours, sevens);
                return 0;
            }
        }
    }

    std::cout << "-1" << std::endl;
    return 0;
}
