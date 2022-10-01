#include <cstdio>
#include <cstring>

unsigned int countVKs(char* s, size_t l) {
    unsigned int c = 0;

    for (int i = 0; i < l - 1; i++) {
        char c1 = s[i];
        char c2 = s[i + 1];

        if (c1 == 'V' && c2 == 'K') {
            c++;
        }
    }

    return c;
}

int extraVK(char* s, size_t l) {
    for (int i = 0; i < l - 1; i++) {
        if (
            (s[i] == 'V' && s[i + 1] == 'V' && (i == l - 2 || s[i + 2] == 'V')) ||
            (s[i] == 'K' && s[i + 1] == 'K')
        ) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char s[100];
    std::scanf("%s", s);
    size_t l = std::strlen(s);

    auto vks = countVKs(s, l) + extraVK(s, l);

    std::printf("%d", vks);
    return 0;
}
