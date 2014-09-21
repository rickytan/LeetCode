#include <iostream>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (container.count(key)) {
            list<pair<int, int> >::iterator it = container[key];
            pair<int, int> theKey = *it;
            order.erase(it);
            order.push_front(theKey);
            container[key] = order.begin();
            return theKey.second;
        }
        else
            return -1;
    }

    void set(int key, int value) {
        if (container.count(key)) {
            container[key]->second = value;
            list<pair<int, int> >::iterator it = container[key];
            pair<int, int> theKey = *it;
            order.erase(it);
            order.push_front(theKey);
            container[key] = order.begin();
        }
        else {
            if (container.size() >= capacity) {
                container.erase(order.back().first);
                order.pop_back();
            }
            order.push_front(make_pair(key, value));
            container[key] = order.begin();
        }
    }

    map<int, list<pair<int, int> >::iterator> container;
    list<pair<int, int> > order;
    int capacity;
};

int main()
{
    LRUCache cache(2);
    cache.set(2, 6);
    cache.set(1, 5);
    cache.set(1, 2);
    cache.get(1);
    return 0;
}