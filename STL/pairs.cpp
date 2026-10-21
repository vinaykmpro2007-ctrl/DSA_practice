#include <bits/stdc++.h> // Includes all standard libraries in one header [00:00:53]
using namespace std;    // Avoids prefixing std:: to cin, cout, vector, etc. [00:01:54]

// ==========================================
// 1. PAIRS (Part of <utility> library) [00:05:37]
// ==========================================
void explainPair() {
    // Basic pair declaration and initialization
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << "\n"; // Output: 1 3 [00:06:41]

    // Nested pair to store 3 or more elements [00:07:23]
    pair<int, pair<int, int>> p_nested = {1, {3, 4}};
    cout << p_nested.first << " " 
         << p_nested.second.first << " " 
         << p_nested.second.second << "\n"; // Output: 1 3 4 [00:08:54]

    // Array of pairs [00:09:05]
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second << "\n"; // Output: 5 [00:09:48]
}
int main()
{   
    explainPair();
    return 0;
}
// ========