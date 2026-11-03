// 07_collision_chaining.cpp
// Collision handling #1: SEPARATE CHAINING
//
// Collision: two different keys map to the same index.
//   With the division rule and size 10:  13 % 10 = 3,  23 % 10 = 3,  33 % 10 = 3.
//
// Chaining: every slot of the table holds a linked list. Keys that hash to the same
// index are simply added to that slot's list.
//
//   index 3 :  13 -> 23 -> 33 -> null
//   index 5 :   5 -> 15 -> null
//
// Complexity (n keys, m slots, load factor alpha = n / m):
//   insert  : O(1)
//   search  : O(1 + alpha) on average, O(n) worst case (all keys in one slot)
//   delete  : O(1 + alpha) on average
//
// Input format:
//   m                 (table size)
//   n
//   k1 ... kn         (keys to insert)
//   q
//   x1 ... xq         (keys to search)
//   d                 (a key to delete)
//
// Compile: g++ -std=c++17 07_collision_chaining.cpp -o 07 && ./07

#include <bits/stdc++.h>
using namespace std;

class ChainingHashTable {
    int size;
    vector<list<int>> table;                 // each slot is a linked list

    int hashFunction(int key) const {
        return key % size;                   // division rule
    }

public:
    ChainingHashTable(int m) : size(m), table(m) {}

    void insert(int key) {
        int idx = hashFunction(key);
        // ignore duplicates
        for (int x : table[idx]) if (x == key) return;
        if (!table[idx].empty())
            cout << "  collision at index " << idx << " while inserting " << key << "\n";
        table[idx].push_back(key);
    }

    bool search(int key) const {
        int idx = hashFunction(key);
        for (int x : table[idx]) {
            if (x == key) return true;
        }
        return false;
    }

    bool erase(int key) {
        int idx = hashFunction(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (*it == key) {
                table[idx].erase(it);
                return true;
            }
        }
        return false;
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            for (int x : table[i]) cout << x << " -> ";
            cout << "null\n";
        }
    }
};

int main() {
    int m;
    cout << "Enter table size: ";
    cin >> m;
    ChainingHashTable ht(m);

    int n;
    cout << "Enter number of keys: ";
    cin >> n;
    cout << "Enter " << n << " keys: ";
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        ht.insert(key);
    }

    cout << "\nHash table:\n";
    ht.display();

    int q;
    cout << "\nEnter number of searches: ";
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << x << (ht.search(x) ? " found" : " not found") << "\n";
    }

    int d;
    cout << "\nEnter a key to delete: ";
    cin >> d;
    cout << (ht.erase(d) ? "deleted " : "not present: ") << d << "\n";

    cout << "\nHash table after delete:\n";
    ht.display();
    return 0;
}