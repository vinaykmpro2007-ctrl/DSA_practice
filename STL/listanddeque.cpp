
#include <iostream>
#include <list>
#include <deque>

using namespace std;

// WHY WE USE print() INSTEAD OF cout:
// C++ does not support 'cout << ls' or 'cout << dq' out of the box because 
// the insertion operator (operator<<) is not defined for STL containers.
// To print them, we must iterate through elements individually. This helper
// template wraps that loop so we don't have to rewrite it repeatedly.
template <typename T>
void print(const T& container) {
    cout << "{ ";
    for (const auto& elem : container) {
        cout << elem << " ";
    }
    cout << "}\n";
}

void explainList() {
    list<int> ls;

    ls.push_back(2);
    print(ls); // { 2 }

    ls.emplace_back(4);
    print(ls); // { 2 4 }

    ls.push_front(5);
    print(ls); // { 5 2 4 }

    // emplace_front requires a value (e.g., 10) to construct the node
    ls.emplace_front(10);
    print(ls); // { 10 5 2 4 }
}

void explainDeque() {
    deque<int> dq;

    dq.push_back(1);
    print(dq); // { 1 }

    dq.emplace_back(2);
    print(dq); // { 1 2 }

    dq.push_front(4);
    print(dq); // { 4 1 2 }

    dq.emplace_front(3);
    print(dq); // { 3 4 1 2 }

    dq.pop_back();
    print(dq); // { 3 4 1 }

    dq.pop_front();
    print(dq); // { 4 1 }

    // dq.back() and dq.front() return references to elements, so cout handles them fine
    cout << "Front element: " << dq.front() << "\n"; // 4
    cout << "Back element: " << dq.back() << "\n";   // 1

    // Random access is supported in deque via operator[]
    cout << "Element at index 0: " << dq[0] << "\n";
}

int main() {
    cout << "--- List Demo ---\n";
    explainList();

    cout << "\n--- Deque Demo ---\n";
    explainDeque();

    return 0;
}