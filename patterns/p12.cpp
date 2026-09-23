/*
    E 
    D E 
    C D E 
    B C D E 
    A B C D E
*/

#include<bits\stdc++.h>
using namespace std;
void printp12(int n)
{  
    for(int i=0;i<n;i++)
    {
        for(char ch='E'-i;ch<='E';ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    printp12(n);
    return 0;
}