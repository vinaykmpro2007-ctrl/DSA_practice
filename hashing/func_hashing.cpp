// 06_hash_functions.cpp
// Hash functions: how a key is turned into an index in [0, size).
//
// 1) Division method        h(k) = k % size
//        Simple and the most common. Choose size as a PRIME (not a power of 2)
//        so keys spread out evenly.
// 2) Folding method         split the key into parts, add the parts, take % size
//        e.g. 123456 -> 123 + 456 = 579 -> 579 % size
// 3) Mid-square method      square the key, take the middle digits, take % size
// 4) Multiplication method  h(k) = floor(size * frac(k * A)),  A ~ 0.6180339887
// 5) String hash            polynomial hash: h = (s[0]*p^0 + s[1]*p^1 + ...) % size
//
// Input format:
//   size       (table size, try a prime like 11)
//   n
//   k1 k2 ... kn   (positive integer keys)
//   word           (a string to hash)
//
// Compile: g++ -std=c++17 06_hash_functions.cpp -o 06 && ./06

#include <bits/stdc++.h>
using namespace std;

// 1) Division method
int divisionHash(long long key, int size) {
    return key % size;
}

// 2) Folding method (3-digit chunks)
int foldingHash(long long key, int size) {
    long long sum = 0;
    while (key > 0) {
        sum += key % 1000;      // take the last 3 digits
        key /= 1000;            // drop them
    }
    return sum % size;
}

// 3) Mid-square method (take the 2 middle digits of key^2)
int midSquareHash(long long key, int size) {
    string sq = to_string(key * key);
    int mid = sq.size() / 2;
    int start = max(0, mid - 1);
    string part = sq.substr(start, 2);
    return stoi(part) % size;
}

// 4) Multiplication method
int multiplicationHash(long long key, int size) {
    const double A = 0.6180339887;               // (sqrt(5) - 1) / 2
    double product = key * A;
    double fraction = product - floor(product);  // fractional part in [0, 1)
    return (int)(size * fraction);
}

// 5) String hash (polynomial rolling hash)
int stringHash(const string &s, int size) {
    const long long p = 31;                      // a small prime base
    long long hash = 0, power = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * power) % size;
        power = (power * p) % size;
    }
    return (int)hash;
}

int main() {
    int size;
    cout << "Enter table size: ";
    cin >> size;

    int n;
    cout << "Enter number of keys: ";
    cin >> n;
    vector<long long> keys(n);
    cout << "Enter " << n << " keys: ";
    for (int i = 0; i < n; i++) cin >> keys[i];

    cout << "\nkey      division  folding  midSquare  multiplication\n";
    for (long long k : keys) {
        cout << left << setw(9) << k
             << setw(10) << divisionHash(k, size)
             << setw(9)  << foldingHash(k, size)
             << setw(11) << midSquareHash(k, size)
             << multiplicationHash(k, size) << "\n";
    }

    string word;
    cout << "\nEnter a lowercase word: ";
    cin >> word;
    cout << "stringHash(\"" << word << "\") = " << stringHash(word, size) << "\n";

    cout << "\nNote: if two keys give the same index, that is a COLLISION"
            " (see files 07 and 08).\n";
    return 0;
}