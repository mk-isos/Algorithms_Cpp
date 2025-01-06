#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    list<int> cache;
    unordered_map<int, list<int>::iterator> hash;

public:
    LRUCache(int cap) : capacity(cap) {}

    void put(int key) {
        if (hash.find(key) != hash.end()) {
            cache.erase(hash[key]);
        } else if (cache.size() == capacity) {
            int last = cache.back();
            cache.pop_back();
            hash.erase(last);
        }
        cache.push_front(key);
        hash[key] = cache.begin();
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