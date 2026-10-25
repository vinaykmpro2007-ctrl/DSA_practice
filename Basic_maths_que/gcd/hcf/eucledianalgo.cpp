#include<bits/stdc++.h>
using namespace std;
void gcd(int a,int b)
{   
    while(a>0 && b>0)
    {
        if(a>b) a=a%b;
        else  b=b%a;
        if(a==0) cout<<"Gcd is :"<<b;
        else cout<<"Gcd is:"<<a;
    } 

}
int main()
{ int n1,n2;
    cout<<"Enter the two numbers:";
    cin>>n1>>n2;
    gcd(n1,n2);
    return 0;
}
// Time complexity is :O(log (min(n1,n2)))