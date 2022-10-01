#include <cstdio>
#include <cstring>

bool isValid(char* seq) {
    auto l = std::strlen(seq);
    int count = 0;
    for (int i = 0; i < l; i++) {
        if (seq[i] == '(') {
            count++;
        } else if (seq[i] == ')') {
            count --;
        }

        if (count < 0) {
            return false;
        }
    }

    return count == 0;
}

int main() {
    char seq[100000];
    std::scanf("%s", seq);

    std::printf("%d", isValid(seq));
    return 0;
}
