#include<bits/stdc++.h>
using namespace std;
bool palindrome(int n)
{
    int d=n;
    int rev=0;
    while(n>0){
        rev=(rev*10)+n%10;
        n=n/10;
    }
    if (d==rev) return true;
    return false;

}
int main()
{ int n;
cout<<"Enter the number:";
cin>>n;
if(palindrome(n))cout<<n<<"is a palindrome number";
else cout<<n<<"is not a palindrome number";
return 0;
}