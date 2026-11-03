// 01_number_hashing.cpp
// Number hashing: pre-store frequencies in an array, then answer each query in O(1).
//
// Problem: given an array of n numbers and q queries, print how many times
//          each queried number appears in the array.
//
// Brute force : O(n) per query  -> O(n * q) total
// Hashing     : O(n) to pre-store, then O(1) per query -> O(n + q) total
//
// Limitation  : array hashing only works when values are small.
//               Max array size: about 1e6 inside main(), about 1e7 if declared globally.
//
// Input format:
//   n
//   a[0] a[1] ... a[n-1]
//   q
//   x1 x2 ... xq
//
// Compile: g++ -std=c++17 01_number_hashing.cpp -o 01 && ./01

#include <bits/stdc++.h>
using namespace std;

// Global array => automatically zero-initialised, and can be large (values up to 1e6).
int hashArr[1000001];

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " numbers (each between 0 and 1000000): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Pre-store: count every number.  O(n)
    for (int i = 0; i < n; i++) {
        hashArr[arr[i]] += 1;
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int number;
        cout << "Query: ";
        cin >> number;

        // Fetch: O(1)
        // Guard against queries outside the array bounds.
        if (number < 0 || number > 1000000) {
            cout << number << " is out of range\n";
        } else {
            cout << number << " appears " << hashArr[number] << " time(s)\n";
        }
    }
    return 0;
}