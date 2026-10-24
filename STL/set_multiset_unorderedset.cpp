#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

// Helper to print elements of set or multiset
template <typename T>
void printContainer(const T& c) {
    cout << "{ ";
    for (const auto& elem : c) {
        cout << elem << " ";
    }
    cout << "}\n";
}

void explainSet() {
    cout << "========================================\n";
    cout << "               STD::SET                 \n";
    cout << "  (Stores unique elements, sorted asc)  \n";
    cout << "========================================\n\n";

    set<int> st;

    // 1. Insertion & Uniqueness
    st.insert(1);
    st.emplace(2);
    st.insert(2); // Duplicate, ignored
    st.insert(4);
    st.insert(3); // Automatically sorted into position

    cout << "1. After inserting 1, 2, 2, 4, 3:\n";
    cout << "   Current set: ";
    printContainer(st);
    cout << "   Note: '2' was added twice but kept once. Elements auto-sort.\n\n";

    // 2. Finding Elements
    cout << "2. Search using find():\n";
    auto it = st.find(3);
    if (it != st.end()) {
        cout << "   find(3): Found element -> " << *it << "\n";
    }

    auto it_not = st.find(6);
    if (it_not == st.end()) {
        cout << "   find(6): Element not found (returns st.end())\n\n";
    }

    // 3. Counting occurrences
    cout << "3. count():\n";
    cout << "   st.count(1): " << st.count(1) << " (returns 1 if present, 0 if absent)\n";
    cout << "   st.count(9): " << st.count(9) << "\n\n";

    // Re-inserting elements to prepare for erasure demos
    st.insert(5);
    cout << "   Current set before erasures: ";
    printContainer(st);

    // 4. Erasing by Value
    st.erase(5); // O(log N)
    cout << "4. After st.erase(5) [by value]:\n";
    cout << "   Current set: ";
    printContainer(st);

    // 5. Erasing by Iterator
    auto it_erase = st.find(3);
    if (it_erase != st.end()) {
        st.erase(it_erase); // Amortized O(1)
        cout << "5. After st.erase(it_erase) where *it_erase == 3 [by iterator]:\n";
        cout << "   Current set: ";
        printContainer(st);
    }

    // Resetting set for range erase and bound demos
    st = {1, 2, 3, 4, 5};
    cout << "\n   Resetting set for range erase: ";
    printContainer(st);

    // 6. Range Erase [first, last)
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // Erases 2 and 3; leaves 4 intact because interval is half-open
    cout << "6. After st.erase(find(2), find(4)) [erases [2, 4)):\n";
    cout << "   Current set: ";
    printContainer(st);
    cout << "\n";

    // 7. Bounds
    st = {10, 20, 30, 40, 50};
    cout << "7. Bounds on set: ";
    printContainer(st);

    // lower_bound(x) >= x
    auto it_lb = st.lower_bound(25);
    cout << "   lower_bound(25) (first element >= 25): " << *it_lb << "\n";

    // upper_bound(x) > x
    auto it_ub = st.upper_bound(30);
    cout << "   upper_bound(30) (first element > 30):  " << *it_ub << "\n\n";
}

void explainMultiset() {
    cout << "========================================\n";
    cout << "             STD::MULTISET              \n";
    cout << "  (Stores duplicate elements, sorted)   \n";
    cout << "========================================\n\n";

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);

    cout << "1. After inserting duplicates {1, 1, 1, 2, 3}:\n";
    cout << "   Current multiset: ";
    printContainer(ms);
    cout << "   ms.count(1): " << ms.count(1) << " instances found\n\n";

    // Erasing a single instance by iterator
    auto it_single = ms.find(1); // Returns iterator to the FIRST instance of 1
    if (it_single != ms.end()) {
        ms.erase(it_single);
        cout << "2. After ms.erase(ms.find(1)) [erasing only ONE instance]:\n";
        cout << "   Current multiset: ";
        printContainer(ms);
        cout << "\n";
    }

    // Erasing all instances by value
    ms.erase(1); // Removes every 1 in the multiset
    cout << "3. After ms.erase(1) [erasing ALL instances by value]:\n";
    cout << "   Current multiset: ";
    printContainer(ms);
    cout << "\n";
}

void explainUSet() {
    cout << "========================================\n";
    cout << "          STD::UNORDERED_SET            \n";
    cout << " (Unique elements, hashed, no order)    \n";
    cout << "========================================\n\n";

    unordered_set<int> ust;
    ust.insert(40);
    ust.insert(10);
    ust.insert(30);
    ust.insert(20);
    ust.insert(10); // Duplicate, ignored

    cout << "1. After inserting {40, 10, 30, 20, 10}:\n";
    cout << "   Current unordered_set: ";
    printContainer(ust);
    cout << "   Notice: Elements are not stored in sorted order.\n";
    cout << "   Average insertion/search time is O(1) instead of O(log N).\n";
    cout << "   Note: lower_bound() / upper_bound() do NOT exist here.\n\n";
}

int main() {
    explainSet();
    explainMultiset();
    explainUSet();
    return 0;
}