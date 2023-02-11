#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight = 0;
    int value = 0;
    bool taken = true;

    Item() {}

    Item(int _weight, int _value) {
        weight = _weight;
        value = _value;
    }
};

class Knapsack {
    public:
    int capacity;
    int currentWeight;
    int currentValue;

    Knapsack(int _capacity, int _currentWeight, int _currentValue) {
        capacity = _capacity;
        currentWeight = _currentWeight;
        currentValue = _currentValue;
    }

    bool isValid() {
        return currentWeight <= capacity;
    }

    Knapsack remove(Item item) const {
        return Knapsack(capacity, currentWeight - item.weight, currentValue - item.value);
    }
};

Item readItem() {
    int weight, value;
    cin >> weight >> value;
    return Item(weight, value);
}

int solve(Knapsack knapsack, vector<Item> items, int subMaxValue = 0) {
    if (knapsack.isValid()) {
        return knapsack.currentValue;
    }

    if (knapsack.currentValue <= subMaxValue) {
        return 0;
    }

    
    for (auto item : items) {
        if (item.taken) {
            auto newKnapsack = knapsack.remove(item);
            if (newKnapsack.isValid()) {
                return newKnapsack.currentValue;
            }
        }
    }

    int maxValue = subMaxValue;
    for (int i = 0; i < items.size(); i++) {
        if (items[i].taken) {
            auto newItems = vector<Item>(items);
            newItems[i].taken = false;

            auto newKnapsack = knapsack.remove(items[i]);
            int newValue = solve(newKnapsack, newItems, maxValue);

            if (newValue > maxValue) {
                maxValue = newValue;
            }
        }
    }

    return maxValue;
}

int main() {
    int n, w;
    cin >> n >> w;

    auto items = vector<Item>(n);
    int totalWeight = 0;
    int totalValue = 0;
    for (int i = 0; i < n; i++) {
        items[i] = readItem();
        totalWeight += items[i].weight;
        totalValue += items[i].value;
    }

    sort(items.begin(), items.end(), [](Item i1, Item i2) {
        return i1.value < i2.value;
    });

    auto knapsack = Knapsack(w, totalWeight, totalValue);

    int result = solve(knapsack, items);
    cout << result << endl;

    return 0;
}
