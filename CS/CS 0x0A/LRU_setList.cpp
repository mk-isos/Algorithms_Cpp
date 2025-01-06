#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

class LRUCache {
    int capacity;
    list<int> cache;
    unordered_set<int> cacheSet;

public:
    LRUCache(int cap) : capacity(cap) {}

    void put(int key) {
        if (cacheSet.find(key) != cacheSet.end()) {
            cache.remove(key);
        } else if (cache.size() == capacity) {
            int last = cache.back();
            cache.pop_back();
            cacheSet.erase(last);
        }
        cache.push_front(key);
        cacheSet.insert(key);
    }

    void display() {
        for (auto it : cache) {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(3);
    cache.put(1);
    cache.put(2);
    cache.put(3);
    cache.display();
    cache.put(4);
    cache.display();
    return 0;
}