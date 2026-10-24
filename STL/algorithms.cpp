#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Helper to print plain integer arrays
void printArray(int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "}\n";
}

// Helper to print pair arrays
void printPairArray(pair<int, int> arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++) {
        cout << "{" << arr[i].first << ", " << arr[i].second << "} ";
    }
    cout << "}\n";
}

// Custom comparator:
// 1. Sort ascending by 'second'
// 2. If 'second' is equal, sort descending by 'first'
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    // p1.second == p2.second: compare first elements in descending order
    return p1.first > p2.first;
}

void explainExtra() {
    cout << "========================================\n";
    cout << "       SORTING BASICS & RANGES          \n";
    cout << "========================================\n\n";

    int a[] = {1, 5, 3, 2};
    int n = 4;

    cout << "Initial array 'a': ";
    printArray(a, n);

    // 1. Full Ascending Sort
    sort(a, a + n);
    cout << "1. Full sort ascending (sort(a, a + n)):\n   ";
    printArray(a, n);
    cout << "\n";

    // 2. Sub-range Sort
    int sub[] = {5, 4, 3, 2, 1};
    cout << "Sub-range target: ";
    printArray(sub, 5);
    sort(sub + 2, sub + 5); // Sorts indices [2, 3, 4], leaves indices 0 and 1 untouched
    cout << "2. Partial sort indices [2, 4] (sort(sub + 2, sub + 5)):\n   ";
    printArray(sub, 5);
    cout << "\n";

    // 3. Descending Sort using greater<T>()
    sort(a, a + n, greater<int>());
    cout << "3. Descending sort using greater<int>() (sort(a, a + n, greater<int>())):\n   ";
    printArray(a, n);
    cout << "\n";

    cout << "========================================\n";
    cout << "           CUSTOM COMPARATORS           \n";
    cout << "========================================\n\n";

    pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};
    int pair_n = 3;

    cout << "Initial pair array:\n   ";
    printPairArray(arr, pair_n);

    // Custom sort:
    // Elements {2, 1} and {4, 1} have identical 'second' (1).
    // Because p1.first > p2.first, {4, 1} precedes {2, 1}.
    // {1, 2} has second = 2, so it lands at the end.
    sort(arr, arr + pair_n, comp);

    cout << "Sorted with custom comparator 'comp' (asc by second, desc by first):\n   ";
    printPairArray(arr, pair_n);
    cout << "\n";

    cout << "========================================\n";
    cout << "           BIT MANIPULATION             \n";
    cout << "========================================\n\n";

    int num = 7; // Binary: 00...0111 (3 set bits)
    int cnt = __builtin_popcount(num);
    cout << "1. __builtin_popcount(" << num << "):\n";
    cout << "   Number of set bits (1s) in binary = " << cnt << "\n\n";

    long long num_ll = 165786578687LL;
    int cnt_ll = __builtin_popcountll(num_ll);
    cout << "2. __builtin_popcountll(" << num_ll << "):\n";
    cout << "   Number of set bits (64-bit integer) = " << cnt_ll << "\n\n";

    cout << "========================================\n";
    cout << "          NEXT PERMUTATION              \n";
    cout << "========================================\n\n";

    string s = "123";
    cout << "All permutations starting from \"" << s << "\" (must be sorted initially):\n";

    int step = 1;
    do {
        cout << "   Permutation #" << step++ << ": " << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    cout << "\nAfter loop ends, string wraps back to sorted order: \"" << s << "\"\n\n";

    cout << "========================================\n";
    cout << "        MAX & MIN ELEMENT LOOKUP        \n";
    cout << "========================================\n\n";

    int values[] = {14, 82, 3, 95, 41};
    int total = 5;

    cout << "Array: ";
    printArray(values, total);

    // *max_element and *min_element return iterators/pointers to target elements
    int maxi = *max_element(values, values + total);
    int mini = *min_element(values, values + total);

    cout << "   *max_element(values, values + 5) = " << maxi << "\n";
    cout << "   *min_element(values, values + 5) = " << mini << "\n";
}

int main() {
    explainExtra();
    return 0;
}