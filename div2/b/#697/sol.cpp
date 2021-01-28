#include <bits/stdc++.h>
 
#define forn(i, n) for(long long int i=3;i<=n;i=i+2)
#define ll long long
using namespace std;
 
long long gcd(long long int t, long long int a){
    
    if(a==0)
        return t;
    long long int r = t%a;
    return gcd(a,r);
}
 
long long int check(ll int a){
    if(a>=2020){
        if(a%2020==0){
            return 0;
        }
        else if(a%2021==0){
            return 0;
        }
        else if(a%10==1){
            return check(a-2021);
        }
        else{
            return check(a-2020);
        }
    }
    else
        return 1;
}
 
int main(){
    ll int t;
    cin>>t;
    
    while(t--){
        ll int a;
        cin>>a;
        int flag = 0;
        
        if(check(a)==0){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    
    return 0;
}
