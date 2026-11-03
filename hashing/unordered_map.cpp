// 04_unordered_map_hashing.cpp
// std::unordered_map  (a real hash table)
//
// Time complexity:
//   insert / access / find / erase : O(1) on average
//                                    O(n) in the WORST case (many keys collide)
//   storing n elements             : O(n) average
//   keys are NOT sorted - iteration order is arbitrary.
//
// When to use which (rule of thumb from the lecture):
//   1) Try unordered_map first - it is usually faster.
//   2) If you get TLE because of worst-case collisions, switch to map.
//
// Limitation: unordered_map has built-in hashes for int, long long, char, string...
//             but NOT for pair<int,int> or vector<int>.  Use map for those.
//
// Input format:
//   n
//   a[0] ... a[n-1]
//   q
//   x1 ... xq
//
// Compile: g++ -std=c++17 04_unordered_map_hashing.cpp -o 04 && ./04

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<long long> arr(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // ---------- Pre-store frequencies ----------
    unordered_map<long long, int> ump;
    for (int i = 0; i < n; i++) {
        ump[arr[i]]++;
    }

    // ---------- Iterate (order is NOT sorted) ----------
    cout << "\nAll frequencies (arbitrary order):\n";
    for (auto it : ump) {
        cout << it.first << " -> " << it.second << "\n";
    }

    // ---------- Queries ----------
    int q;
    cout << "\nEnter number of queries: ";
    cin >> q;
    while (q--) {
        long long number;
        cout << "Query: ";
        cin >> number;

        auto it = ump.find(number);       // find() does not insert
        if (it == ump.end()) cout << number << " appears 0 time(s)\n";
        else                 cout << number << " appears " << it->second << " time(s)\n";
    }

    // ---------- Other common operations ----------
    cout << "\nSize                 : " << ump.size() << "\n";
    cout << "Bucket count         : " << ump.bucket_count() << "\n";
    cout << "Contains 5?          : " << (ump.count(5) ? "yes" : "no") << "\n";
    if (!ump.empty()) {
        long long k = arr[0];
        ump.erase(k);
        cout << "Erased key " << k << ", size now " << ump.size() << "\n";
    }

    return 0;
}