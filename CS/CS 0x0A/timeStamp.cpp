#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class LRUCache {
    int capacity;
    unordered_map<int, pair<int, int>> cache; // key -> {value, timestamp}
    int time = 0;

public:
    LRUCache(int cap) : capacity(cap) {}

    void put(int key, int value) {
        time++;
        if (cache.size() == capacity) {
            auto it = min_element(cache.begin(), cache.end(), [](const auto &a, const auto &b) {
                return a.second.second < b.second.second;
            });
            cache.erase(it->first);
        }
        cache[key] = {value, time};
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        cache[key].second = ++time;
        return cache[key].first;
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    cout << "Key 1: " << cache.get(1) << endl;
    cache.put(3, 30); // Key 2 제거
    cout << "Key 2: " << cache.get(2) << endl;
    return 0;
}