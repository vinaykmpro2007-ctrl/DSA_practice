// 02_character_hashing.cpp
// Character hashing: count how many times each character appears in a string.
//
// Two ways to size the hash array:
//   1) Only lowercase letters 'a'..'z'  -> array of size 26,  index = ch - 'a'
//   2) Any ASCII character              -> array of size 256, index = (int)ch
//
// Characters are really numbers (ASCII), so character hashing is just number
// hashing with a small value range.  'a' = 97, 'b' = 98, ..., 'z' = 122.
//
// Input format:
//   s            (a single word, no spaces)
//   q
//   c1 c2 ... cq (characters to query)
//
// Compile: g++ -std=c++17 02_character_hashing.cpp -o 02 && ./02

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // ---------- Method 1: lowercase only (size 26) ----------
    int hash26[26] = {0};
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            hash26[s[i] - 'a']++;          // 'a' -> 0, 'b' -> 1, ...
    }

    // ---------- Method 2: any ASCII character (size 256) ----------
    int hash256[256] = {0};
    for (int i = 0; i < (int)s.size(); i++) {
        hash256[(unsigned char)s[i]]++;    // cast avoids negative index for odd chars
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        char c;
        cout << "Query character: ";
        cin >> c;

        int fromSmall = 0;
        if (c >= 'a' && c <= 'z') fromSmall = hash26[c - 'a'];

        cout << "'" << c << "' appears " << hash256[(unsigned char)c]
             << " time(s)  (26-array says " << fromSmall << ")\n";
    }
    return 0;
}