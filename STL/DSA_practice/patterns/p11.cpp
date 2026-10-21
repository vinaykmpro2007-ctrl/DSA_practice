/*
        A
       ABA
      ABCBA
     ABCDCBA
    ABCDEDCBA

*/
#include <iostream>
using namespace std;

void printp11(int n) {
    for (int i = 0; i < n; i++) {
        // 1. Print leading spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }

        // 2. Print palindrome characters
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2; // Midpoint index: i
        for (int j = 1; j <= 2 * i + 1; j++) {
            cout << ch;
            if (j <= breakpoint) {
                ch++;
            } else {
                ch--;
            }
        }

        // 3. Move to the next line
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    printp11(n);
    return 0;
}