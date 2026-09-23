#include <iostream>
using namespace std;

void printp13(int n)
{
    // --- Top Half ---
    for (int i = 0; i < n; i++)
    {
        // Left stars: n - i
        for (int j = 0; j < n - i; j++) cout << "*";

        // Middle spaces: 2 * i
        for (int j = 0; j < 2 * i; j++) cout << " ";

        // Right stars: n - i
        for (int j = 0; j < n - i; j++) cout << "*";

        cout << "\n";
    }

    // --- Bottom Half ---
    for (int i = 0; i < n; i++)
    {
        // Left stars: i + 1
        for (int j = 0; j <= i; j++) cout << "*";

        // Middle spaces: 2 * (n - 1 - i)
        for (int j = 0; j < 2 * (n - 1 - i); j++) cout << " ";

        // Right stars: i + 1
        for (int j = 0; j <= i; j++) cout << "*";

        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter the number of lines (half height, e.g., 5): ";
    cin >> n;
    printp13(n);
    return 0;
}