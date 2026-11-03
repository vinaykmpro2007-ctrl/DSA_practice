// 05_time_complexity.cpp
// Compares the running time of the three hashing approaches and shows how
// unordered_map degrades to O(n) per operation when everything collides.
//
//   Approach              store n items      one query        Notes
//   --------------------  -----------------  ---------------  -------------------------------
//   Array hashing         O(n)               O(1)             only for small values
//   map                   O(n log n)         O(log n)         guaranteed, any case
//   unordered_map         O(n) average       O(1) average     O(n) per op in the worst case
//
// Part 1 : timing on random data.
// Part 2 : worst case - a deliberately terrible hash function sends every key
//          to the same bucket, so unordered_map becomes a linked list (O(n) per op).
//
// Compile: g++ -O2 -std=c++17 05_time_complexity.cpp -o 05 && ./05

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

static long long elapsedMs(steady_clock::time_point a, steady_clock::time_point b) {
    return duration_cast<milliseconds>(b - a).count();
}

// A bad hash: every key gets the same hash value -> every key collides.
struct BadHash {
    size_t operator()(int) const { return 1; }
};

int main() {
    // ---------------- Part 1: random data ----------------
    const int N = 1000000;
    const int MAXV = 1000000;
    mt19937 rng(12345);
    vector<int> data(N);
    for (int &x : data) x = rng() % (MAXV + 1);

    cout << "Part 1: " << N << " random numbers in [0, " << MAXV << "]\n";

    // Array hashing
    auto t0 = steady_clock::now();
    vector<int> arr(MAXV + 1, 0);
    for (int x : data) arr[x]++;
    auto t1 = steady_clock::now();

    // map
    map<int, int> m;
    for (int x : data) m[x]++;
    auto t2 = steady_clock::now();

    // unordered_map
    unordered_map<int, int> um;
    um.reserve(N);
    for (int x : data) um[x]++;
    auto t3 = steady_clock::now();

    cout << "  array         : " << elapsedMs(t0, t1) << " ms\n";
    cout << "  map           : " << elapsedMs(t1, t2) << " ms\n";
    cout << "  unordered_map : " << elapsedMs(t2, t3) << " ms\n";

    // ---------------- Part 2: worst case ----------------
    const int M = 20000;
    cout << "\nPart 2: worst case, " << M << " distinct keys\n";

    auto t4 = steady_clock::now();
    unordered_map<int, int> good;
    for (int i = 0; i < M; i++) good[i]++;
    auto t5 = steady_clock::now();

    unordered_map<int, int, BadHash> bad;     // every key collides
    for (int i = 0; i < M; i++) bad[i]++;
    auto t6 = steady_clock::now();

    map<int, int> tree;
    for (int i = 0; i < M; i++) tree[i]++;
    auto t7 = steady_clock::now();

    cout << "  unordered_map, normal hash : " << elapsedMs(t4, t5) << " ms\n";
    cout << "  unordered_map, bad hash    : " << elapsedMs(t5, t6) << " ms  (O(n^2) overall)\n";
    cout << "  map                        : " << elapsedMs(t6, t7) << " ms  (still O(n log n))\n";

    cout << "\nRule: try unordered_map first; if it gets TLE, use map.\n";
    return 0;
}