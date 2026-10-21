/*
    5 5 5 5 5 5 5 5 5 
    5 4 4 4 4 4 4 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 2 1 2 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 4 4 4 4 4 4 5 
    5 5 5 5 5 5 5 5 5
*/
#include<bits/stdc++.h>
using namespace std;

void printp16(int n)
{
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int bottom = size - 1 - i;
            int right = size - 1 - j;
            
            int minDist = min({top, left, bottom, right});
            cout << (n - minDist) << " ";
        }
        cout << "\n";
    }
}


int main()
{
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    printp16(n);
    return 0;
}
