#include <cstdio>
#include <cstring>
#include <cstdlib>

int charToInt(char c) {
    return c - '0';
}

int main() {
    char s[300000];
    std::scanf("%s", s);

    unsigned long long l = std::strlen(s);
    unsigned long long count = 0;

    for (int i = 0; i < l - 1; i++) {
        int d1 = charToInt(s[i]);
        if (d1 % 4 == 0) {
            count++;
        }

        int d2 = charToInt(s[i]) * 10 + charToInt(s[i + 1]);
        if (d2 % 4 == 0) {
            count += i + 1;
        }
    }

    int ld = charToInt(s[l - 1]);
    if (ld % 4 == 0) {
        count++;
    }

    std::printf("%Lu", count);
    return 0;
}
