#include<bits/stdc++.h>

using namespace std;

void explainVector() {
    // Basic declaration & push
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    // Vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    // Initializations
    vector<int> v1(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v2(5);      // {0, 0, 0, 0, 0}
    vector<int> v3(5, 20);  // {20, 20, 20, 20, 20}
    vector<int> v4(v3);     // Copy of v3

    // Assign 5 elements so iterator arithmetic below doesn't exceed bounds
    v = {20, 10, 15, 6, 7};

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " "; // 10

    it = it + 2;
    cout << *(it) << " "; // 6

    cout << v[0] << " " << v.at(0) << " "; // 20 20
    cout << v.back() << "\n";              // 7

    // Printing methods
    cout << "Iterator loop: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << "\n";

    cout << "Auto iterator loop: ";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
    cout << "\n";

    cout << "Range-based for loop: ";
    for (auto it : v) {
        cout << it << " ";
    }
    cout << "\n";

    // Erase operations on {20, 10, 15, 6, 7}
    v.erase(v.begin() + 1);                // removes 10 -> {20, 15, 6, 7}
    v.erase(v.begin() + 1, v.begin() + 3); // removes [15, 6) -> {20, 7}

    // Insert function
    vector<int> v_ins(2, 100);              // {100, 100}
    v_ins.insert(v_ins.begin(), 300);       // {300, 100, 100}
    v_ins.insert(v_ins.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copy(2, 50); // {50, 50}
    v_ins.insert(v_ins.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    cout << "v size: " << v.size() << "\n"; // 2
    v.pop_back();                           // {20}

    // Swap
    v1.swap(v2);

    // Clear
    v.clear();
    cout << "Is v empty? " << (v.empty() ? "Yes" : "No") << "\n";
}

int main() {
    explainVector();
    return 0;
}