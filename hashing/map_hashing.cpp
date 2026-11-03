// 03_map_hashing.cpp
// std::map  (ordered map, implemented as a balanced binary search tree)
//
// Use it when the values are too large for an array (e.g. up to 1e9) or the keys
// are not numbers at all (strings, pairs, ...).
//
// Time complexity (in ALL cases):
//   insert / access / find / erase : O(log n)
//   storing n elements             : O(n log n)
//   keys are always kept SORTED.
//
// Input format:
//   n
//   a[0] ... a[n-1]    (values can be as big as 1e9)
//   q
//   x1 ... xq
//
// Compile: g++ -std=c++17 03_map_hashing.cpp -o 03 && ./03

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
    map<long long, int> mp;               // key = number, value = frequency
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;                     // a missing key is created with value 0, then ++
    }

    // ---------- Iterate (always in sorted key order) ----------
    cout << "\nAll frequencies (sorted by key):\n";
    for (auto it : mp) {
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

        // Use find() so that checking does NOT insert the key.
        // (mp[number] on a missing key would insert it with value 0!)
        auto it = mp.find(number);
        if (it == mp.end()) cout << number << " appears 0 time(s)\n";
        else                cout << number << " appears " << it->second << " time(s)\n";
    }

    // ---------- Other common operations ----------
    cout << "\nSize of map          : " << mp.size() << "\n";
    cout << "Smallest key         : " << mp.begin()->first << "\n";
    cout << "Largest key          : " << mp.rbegin()->first << "\n";
    if (mp.count(arr[0])) {
        mp.erase(arr[0]);                 // erase by key
        cout << "Erased key " << arr[0] << ", size now " << mp.size() << "\n";
    }

    // ---------- Map with string keys: word frequency ----------
    cout << "\nWord frequency of \"to be or not to be\":\n";
    string sentence = "to be or not to be";
    map<string, int> words;
    stringstream ss(sentence);
    string w;
    while (ss >> w) words[w]++;
    for (auto &p : words) cout << p.first << " -> " << p.second << "\n";

    return 0;
}
