/*
    *        *
    **      **
    ***    ***
    ****  ****
    **********
    ****  ****
    ***    ***
    **      **
    *        *
*/
#include <iostream>
using namespace std;

void printp14(int n)
{
    int spaces = 2 * n - 2;

    for (int i = 1; i <= 2 * n - 1; i++)
    {
        // Stars count increases up to row n, then decreases
        int stars = (i <= n) ? i : (2 * n - i);

        // 1. Left stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        // 2. Spaces in middle
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        // 3. Right stars
        for (int j = 1; j <= stars; j++) {
            cout << "*";
        }

        cout << "\n";

        // Update space count for next row
        if (i < n) {
            spaces -= 2;
        } else {
            spaces += 2;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    printp14(n);
    return 0;
}
