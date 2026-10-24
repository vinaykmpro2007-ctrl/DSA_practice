#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

// Helper to print key-value pairs of any map-like container
template <typename T>
void printMap(const T &m)
{
    cout << "   [ ";
    for (const auto &pair : m)
    {
        cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    cout << "]\n";
}

void explainMap()
{
    cout << "========================================\n";
    cout << "               STD::MAP                 \n";
    cout << " (Unique keys, sorted by key, Red-Black) \n";
    cout << "========================================\n\n";

    map<int, string> mp;

    // 1. Insertion
    mp[1] = "Apple";
    mp[3] = "Cherry";
    mp.insert({2, "Banana"});
    mp.emplace(5, "Elderberry");
    mp.insert({2, "Blueberry"}); // Duplicate key '2', ignored!

    cout << "1. After inserting keys 1, 3, 2, 5, and duplicate key 2:\n";
    printMap(mp);
    cout << "   Notice: Keys are automatically kept in ascending order.\n";
    cout << "   The duplicate insert({2, \"Blueberry\"}) did not overwrite existing value.\n\n";

    // 2. Safe Search vs operator[]
    cout << "2. Searching for keys:\n";
    auto it = mp.find(3);
    if (it != mp.end())
    {
        cout << "   mp.find(3): Found -> Key: " << it->first << ", Value: " << it->second << "\n";
    }

    auto it_not = mp.find(99);
    if (it_not == mp.end())
    {
        cout << "   mp.find(99): Not found (safely returned mp.end())\n";
    }

    // 3. The bracket operator trap: mp[key] creates default value if missing
    cout << "\n3. Operator [] behavior on non-existent key:\n";
    cout << "   Before access, size is: " << mp.size() << "\n";
    cout << "   Evaluating mp[10] produces: \"" << mp[10] << "\"\n";
    cout << "   After access, size is: " << mp.size() << " (Key 10 got silently inserted!)\n";
    printMap(mp);
    cout << "\n";

    // 4. Erase
    mp.erase(10); // Erase by key
    cout << "4. After mp.erase(10):\n";
    printMap(mp);
    cout << "\n";

    // 5. Lower Bound and Upper Bound
    cout << "5. Bounds on keys (O(log N)):\n";
    auto lb = mp.lower_bound(2); // First key >= 2
    auto ub = mp.upper_bound(2); // First key > 2
    cout << "   lower_bound(2) -> Key: " << lb->first << ", Value: " << lb->second << "\n";
    cout << "   upper_bound(2) -> Key: " << ub->first << ", Value: " << ub->second << "\n\n";
}

void explainMultimap()
{
    cout << "========================================\n";
    cout << "             STD::MULTIMAP              \n";
    cout << " (Duplicate keys allowed, sorted by key) \n";
    cout << "========================================\n\n";

    multimap<string, int> mmp;

    // operator[] is NOT supported on multimap because keys are not unique
    mmp.insert({"apple", 50});
    mmp.insert({"banana", 20});
    mmp.insert({"apple", 75}); // Duplicate key "apple"
    mmp.insert({"cherry", 30});
    mmp.insert({"apple", 100}); // Another duplicate

    cout << "1. After inserting multiple duplicate keys:\n";
    printMap(mmp);
    cout << "   Count of 'apple': " << mmp.count("apple") << "\n\n";

    // Finding all values for a duplicate key using equal_range
    cout << "2. Iterating all entries for key 'apple' using equal_range:\n";
    auto range = mmp.equal_range("apple");
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << "   -> " << it->first << " costs " << it->second << "\n";
    }
    cout << "\n";

    // Erase: by iterator (single item) vs by key (all matching items)
    auto single = mmp.find("apple"); // Iterator to first occurrence
    mmp.erase(single);
    cout << "3. After erasing ONE occurrence of 'apple' via iterator:\n";
    printMap(mmp);

    mmp.erase("apple"); // Erases ALL remaining occurrences of "apple"
    cout << "4. After erasing by key 'apple' (erases ALL instances):\n";
    printMap(mmp);
    cout << "\n";
}

void explainUnorderedMap()
{
    cout << "========================================\n";
    cout << "          STD::UNORDERED_MAP            \n";
    cout << "    (Unique keys, Hash Table, O(1) avg)  \n";
    cout << "========================================\n\n";

    unordered_map<string, int> freq;

    // Word frequency counting idiom
    string words[] = {"code", "debug", "code", "run", "code", "run"};
    for (const string &w : words)
    {
        freq[w]++; // Automatically initializes to 0 on first encounter, then increments
    }

    cout << "1. Word frequency after counting:\n";
    printMap(freq);
    cout << "   Notice: Ordering depends on hash values/buckets, not alphabetical.\n\n";

    cout << "2. Direct lookup: freq[\"code\"] = " << freq["code"] << "\n";
    cout << "   Average search/insert time: O(1)\n";
    cout << "   Worst case (hash collisions): O(N)\n";
    cout << "   Note: lower_bound / upper_bound are NOT supported.\n\n";
}

int main()
{
    explainMap();
    explainMultimap();
    explainUnorderedMap();
    return 0;
}