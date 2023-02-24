// Solution for https://codeforces.com/problemset/problem/797/B

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <map>
using namespace std;

// odd: 2 -5 -3
// even: 2 -5
// 

bool isEven(int n) {
    return n % 2 == 0;
}

class IntOrNothing {
    private:
    bool _something;
    int _value;

    public:
    IntOrNothing(int value = INT_MIN) {
        _value = value;
        _something = value != INT_MIN;
    }

    int operator+(int other) {
        return _something ? _value + other : INT_MIN;
    }

    int something() {
        return _something;
    }

    int value() {
        return _value;
    }
};

class Solver {
    private:
    map<pair<int, bool>, IntOrNothing> _memo = map<pair<int, bool>, IntOrNothing>();

    public:
    IntOrNothing solve(vector<int>& a, int headIdx, bool odd = true) {
        try {
            return _memo.at({headIdx, odd});
        } catch (...) {}

        if (headIdx == 0) return odd ? IntOrNothing() : IntOrNothing(0);
        auto head = a[headIdx - 1];

        if (odd) {
            if (isEven(head)) {
                auto oddResult = solve(a, headIdx - 1, true);
                auto value = max({
                    oddResult + 0,
                    oddResult + head
                });

                _memo[{headIdx, odd}] = IntOrNothing(value);
                return IntOrNothing(value);
            } else {
                auto evenResult = solve(a, headIdx - 1, false);
                auto oddResult = solve(a, headIdx - 1, true);
                auto value = max({
                    evenResult + head,
                    oddResult + 0,
                    head
                });

                _memo[{headIdx, odd}] = IntOrNothing(value);
                return IntOrNothing(value);
            }
        } else {
            if (isEven(head)) {
                auto evenResult = solve(a, headIdx - 1, false);
                auto value = max({
                    evenResult + 0,
                    evenResult + head,
                    head,
                    0
                });

                _memo[{headIdx, odd}] = IntOrNothing(value);
                return IntOrNothing(value);
            } else {
                auto oddResult = solve(a, headIdx - 1, true);
                auto evenResult = solve(a, headIdx - 1, false);
                auto value = max({
                    oddResult + head,
                    evenResult + 0,
                    0
                });

                _memo[{headIdx, odd}] = IntOrNothing(value);
                return IntOrNothing(value);
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    auto a = vector<int>(n);
    for (auto& ai : a) cin >> ai;

    auto solver = Solver();
    cout << solver.solve(a, n).value() << endl;
    return 0;
}
