#include<bits/stdc++.h>
using namespace std;
void gcd(int n1,int n2)
{   int gcd=1;
    for(int i=1;i<=min(n1,n2);i++)
    {
        if(n1%i==0 && n2%i==0)gcd=i;
        
    }
    cout<<"Gcd is:"<<gcd;
}
int main()
{ int n1,n2;
    cout<<"Enter the two numbers:";
    cin>>n1>>n2;
    gcd(n1,n2);
    return 0;
    

}
// Time complexity: O(min(n1,n2))