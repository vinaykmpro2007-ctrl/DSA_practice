#include<bits/stdc++.h>
using namespace std;
bool arms(int n)
{
    int nd=0,d=n,sum=0,n1=n;
    while(n1>0){
        n1=n1/10;
        nd++;
    }
    while(n>0)
    { int ld=n%10;
      sum+=pow(ld,nd);
      n=n/10;
    }
    if(sum==d) return true;
    return false;
}
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    if(arms(n)) cout<<n<<" is a armstrong number";
    else cout<<n<<" is not a armstrong number";
    return 0;
}